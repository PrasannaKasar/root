#ifndef ROOT_TMVA_SOFIE_TANH_GPU 
#define ROOT_TMVA_SOFIE_TANH_GPU 

#include <cmath> 
#include <vector> 
#include "TMVA/SOFIE_common.hxx" 
#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

namespace TMVA_SOFIE_Tanh_GPU { 
struct Session { 

// kernel source function 


//------ TANH
const char* kernelSource = "__kernel void Tanh(__global const float* A, __global float* C) {\n"
"  int id = get_global_id(0);\n"
"  if (id < 24) {\n"
"    C[id] = tanh(A[id]);\n"
"  }\n"
"}";
#define VECTOR_SIZE 24
char* fIntermediateMemoryPool = new char[24*4]; 
float* C = reinterpret_cast<float*>(fIntermediateMemoryPool + 0); 

Session(std::string = "") { 
  //---- allocate the intermediate dynamic tensors 
} 
std::vector<float> infer(float* tensor_input) { 
float* A = tensor_input; 

cl_int err;
cl_uint numPlatforms;
err = clGetPlatformIDs(0, NULL, &numPlatforms);
if (err != CL_SUCCESS || numPlatforms == 0) {
   fprintf(stderr, "Error: Failed to find any OpenCL platforms. Error code %d\n", err);
   return std::vector<float> {};
}
cl_platform_id *platforms = (cl_platform_id *)malloc(numPlatforms * sizeof(cl_platform_id));
err = clGetPlatformIDs(numPlatforms, platforms, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to get OpenCL platform IDs. Error code %d\n", err);
   free(platforms);
   return std::vector<float> {};
}
// Use the first available platform
cl_platform_id platform = platforms[0];
free(platforms);

cl_device_id device;
err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_DEFAULT, 1, &device, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to get an OpenCL device. Error code %d\n", err);
   return std::vector<float> {};
}

cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create a context. Error code %d\n", err);
   return std::vector<float> {};
}

// Use clCreateCommandQueueWithProperties instead of deprecated clCreateCommandQueue
cl_command_queue queue = clCreateCommandQueueWithProperties(context, device, 0, &err);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create a command queue. Error code %d\n", err);
   clReleaseContext(context);
   return std::vector<float> {};
}

// Create buffers
cl_mem bufferA = clCreateBuffer(context, CL_MEM_READ_ONLY, VECTOR_SIZE * sizeof(float), NULL, &err);
cl_mem bufferC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, VECTOR_SIZE * sizeof(float), NULL, &err);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create buffers. Error code %d\n", err);
   clReleaseCommandQueue(queue);
   clReleaseContext(context);
   return std::vector<float> {};
}

// Write data to device buffers
err = clEnqueueWriteBuffer(queue, bufferA, CL_TRUE, 0, VECTOR_SIZE * sizeof(float), A, 0, NULL, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to write to bufferA. Error code %d\n", err);
   return std::vector<float> {};
}
// Create and build program
cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, &err);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create program. Error code %d\n", err);
   return std::vector<float> {};
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
   return std::vector<float> {};
}

// Create kernel
   std::string kernelName = "Tanh"; 
cl_kernel kernel = clCreateKernel(program, kernelName.c_str(), &err); 
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to create kernel. Error code %d\n", err);
   return std::vector<float> {};
}

// Set kernel arguments
err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);
err = clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferC);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to set kernel arguments. Error code %d\n", err);
   return std::vector<float> {};
}

// Enqueue kernel execution
size_t globalSize = VECTOR_SIZE;
err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to enqueue kernel. Error code %d\n", err);
   return std::vector<float> {};
}

// Ensure that all operations are complete
clFinish(queue);

// Read back the results from device memory
err = clEnqueueReadBuffer(queue, bufferC, CL_TRUE, 0, VECTOR_SIZE * sizeof(float), C, 0, NULL, NULL);
if (err != CL_SUCCESS) {
   fprintf(stderr, "Error: Failed to read bufferC. Error code %d\n", err);
   return std::vector<float> {};
}


// Cleanup
clReleaseKernel(kernel);
clReleaseProgram(program);
clReleaseMemObject(bufferA);
clReleaseMemObject(bufferC);
clReleaseCommandQueue(queue);
clReleaseContext(context);
std::vector<float> ret(C, C + 24); 
return ret; 
} 
}; 
} 
#endif 
