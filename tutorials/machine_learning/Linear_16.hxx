#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// kernel source function 

#define VECTOR_SIZE #define VECTOR_SIZE #define VECTOR_SIZE #define VECTOR_SIZE #define VECTOR_SIZE #define VECTOR_SIZE #define VECTOR_SIZE #define VECTOR_SIZE #define VECTOR_SIZE #define VECTOR_SIZE 
cl_int err;
cl_uint numPlatforms;
err = clGetPlatformIDs(0, NULL, &numPlatforms);
if (err != CL_SUCCESS || numPlatforms == 0) {
   fprintf(stderr, "Error: Failed to find any OpenCL platforms. Error code %d\n", err);
   return EXIT_FAILURE;
}
cl_platform_id *platforms = malloc(numPlatforms * sizeof(cl_platform_id));
err = clGetPlatformIDs(numPlatforms, platforms, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to get OpenCL platform IDs. Error code %d\n", err);
   free(platforms);
   return EXIT_FAILURE;
}
// Use the first available platform
cl_platform_id platform = platforms[0];
free(platforms);

cl_device_id device;
err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_DEFAULT, 1, &device, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to get an OpenCL device. Error code %d\n", err);
   return EXIT_FAILURE;
}

cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create a context. Error code %d\n", err);
   return EXIT_FAILURE;
}

// Use clCreateCommandQueueWithProperties instead of deprecated clCreateCommandQueue
cl_command_queue queue = clCreateCommandQueueWithProperties(context, device, 0, &err);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create a command queue. Error code %d\n", err);
   clReleaseContext(context);
   return EXIT_FAILURE;
}

// Create buffers
cl_mem bufferA = clCreateBuffer(context, CL_MEM_READ_ONLY, VECTOR_SIZE * sizeof(float), NULL, &err);
cl_mem bufferC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, VECTOR_SIZE * sizeof(float), NULL, &err);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create buffers. Error code %d\n", err);
   clReleaseCommandQueue(queue);
   clReleaseContext(context);
   return EXIT_FAILURE;
}

// Write data to device buffers
err = clEnqueueWriteBuffer(queue, bufferA, CL_TRUE, 0, VECTOR_SIZE * sizeof(float), A, 0, NULL, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to write to bufferA. Error code %d\n", err);
   return EXIT_FAILURE;
}
// Create and build program
cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, &err);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create program. Error code %d\n", err);
   return EXIT_FAILURE;
}
err = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
if (err != CL_SUCCESS) {
   // Retrieve and print the build log
   size_t log_size;
   clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
   char *log = (char *)malloc(log_size);
   clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
   fprintf(stderr, "Error: Failed to build program. Build log:\n%s\n", log);
   free(log);
   return EXIT_FAILURE;
}

// Create kernel
   std::string kernelName = relu; 
   std::string kernelName = relu; 
   std::string kernelName = relu; 
   std::string kernelName = relu; 
   std::string kernelName = relu; 
   std::string kernelName = relu; 
   std::string kernelName = relu; 
   std::string kernelName = relu; 
   std::string kernelName = relu; 
   std::string kernelName = relu; 
cl_kernel kernel = clCreateKernel(program, kernelName.c_str(), &err)if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create kernel. Error code %d\n", err);
   return EXIT_FAILURE;
}

// Set kernel arguments
err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);
err = clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferC);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to set kernel arguments. Error code %d\n", err);
   return EXIT_FAILURE;
}

// Enqueue kernel execution
size_t globalSize = VECTOR_SIZE;
err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to enqueue kernel. Error code %d\n", err);
   return EXIT_FAILURE;
}

// Ensure that all operations are complete
clFinish(queue);

// Read back the results from device memory
err = clEnqueueReadBuffer(queue, bufferC, CL_TRUE, 0, VECTOR_SIZE * sizeof(float), C, 0, NULL, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to read bufferC. Error code %d\n", err);
   return EXIT_FAILURE;
}


// Cleanup
clReleaseKernel(kernel);
clReleaseProgram(program);
clReleaseMemObject(bufferA);
clReleaseMemObject(bufferC);
clReleaseCommandQueue(queue);
clReleaseContext(context);
