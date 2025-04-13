#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>
#include <clBLAS.h>

#define M 4 // Number of rows in matrices A and C
#define N 6 // Number of columns in matrices B and C
#define K 5 // Number of columns in matrix A and rows in matrix B

int main() {
    // Initialize OpenCL environment
    cl_platform_id platform = NULL;
    cl_device_id device = NULL;
    cl_context context = NULL;
    cl_command_queue queue = NULL;
    cl_int err;

    err = clGetPlatformIDs(1, &platform, NULL);
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
    context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
    queue = clCreateCommandQueue(context, device, 0, &err);

    // Initialize clBLAS
    err = clblasSetup();

    // Prepare matrices
    float alpha = 2;
    float beta = 3;
    float A[M * K] = {  0.5743, -0.9235, 0.1657, 1.4821, -0.2758, 0.9034, -1.1674, 0.7412, -0.5983, 0.3139, 
                        1.0872, -0.6821, 0.4379, -1.0456, -0.1784, 0.0567, 0.8982, -0.9823, 1.5678, -0.4235 };

    float B[K * N] = {  0.5743, -0.9235, 0.1657, 1.4821, -0.2758, 0.9034, -1.1674, 0.7412, -0.5983, 0.3139, 
                        1.0872, -0.6821, 0.4379, -1.0456, -0.1784, 0.0567, 0.8982, -0.9823, 1.5678, -0.4235, 
                        -0.2945, 0.8751, 1.3594, -1.2136, 0.7419, -0.5612, 0.4342, 1.2394, -0.8360, 0.6573 };

    float C[M * N] = {  -0.3896, -0.3521,  0.0363,  1.0962,  0.5085, -0.8523, -0.6766,  0.2421,
                        1.5971,  1.3873, -0.2112, -0.6895, -0.5069, -2.1395, -0.7087,  1.1658,
                        1.3493,  0.8132,  1.7156, -0.8637, -0.1971,  0.0411, -0.5662, -0.2516 };
    // for (int i = 0; i < M * K; i++) A[i] = (float)(i + 1);
    // for (int i = 0; i < K * N; i++) B[i] = (float)(-i - 1);
    // for (int i = 0; i < M * N; i++) C[i] = (float)(i - 1);

    // Create OpenCL memory buffers
    cl_mem bufA = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                                 M * K * sizeof(float), A, &err);
    cl_mem bufB = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                                 K * N * sizeof(float), B, &err);
    cl_mem bufC = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                 M * N * sizeof(float), C, &err);

    // Perform GEMM: C = alpha * A * B + beta * C
    // M = Number of rows in matrices A and C
    // N = Number of columns in matrices B and C
    // K = Number of columns in matrix A and rows in matrix B
    err = clblasSgemm(clblasRowMajor, clblasNoTrans, clblasNoTrans, 
        M, N, K, alpha, bufA, 0, K, bufB, 0, N, 
        beta, bufC, 0, N, 1, &queue, 0, NULL, NULL);


    // Wait for calculations to be finished
    err = clFinish(queue);

    // Fetch results
    err = clEnqueueReadBuffer(queue, bufC, CL_TRUE, 0,
                              M * N * sizeof(float),
                              C, 0, NULL, NULL);

    // Release OpenCL resources
    clReleaseMemObject(bufA);
    clReleaseMemObject(bufB);
    clReleaseMemObject(bufC);
    clblasTeardown();
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    // Print results
    for (int i = 0; i < M*N; i++) {
        printf("%f \n", C[i]);
        // printf("\n");
    }

    return 0;
}
