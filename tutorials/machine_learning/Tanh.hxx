#ifndef ROOT_TMVA_SOFIE_TANH_GPU 
#define ROOT_TMVA_SOFIE_TANH_GPU 
#include <cmath> 
#include <vector> 
#include "TMVA/SOFIE_common.hxx" 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <CL/cl.h> 
#include <clBLAS.h> 
namespace TMVA_SOFIE_Tanh_GPU { 
struct Session {

//--- Allocating session memory pool to be used for allocating intermediate tensors
char* fIntermediateMemoryPool = new char[96];


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor 1 with size 96 bytes
float* tensor_1= reinterpret_cast<float*>(fIntermediateMemoryPool + 0);


Session(std::string filename ="Tanh.dat") {

//--- reading weights from file

//---- allocate the intermediate dynamic tensors
}



std::vector<float> infer(float* tensor_onnxTanh_0){

//------ TANH
const char* kernelSource = "__kernel void Tanh(__global const float* A, __global float* C) {\n"
"  int id = get_global_id(0);\n"
"  if (id < 24) {\n"
"    C[id] = tanh(A[id]);\n"
"  }\n"
"}";

cl_int err;
cl_uint numPlatforms;
err = clGetPlatformIDs(0, NULL, &numPlatforms);
if (err != CL_SUCCESS || numPlatforms == 0) {
  fprintf(stderr, "Error: Failed to find any OpenCL platforms. Error code %d\n", err);
  return std::vector<float> {};
}
cl_platform_id* platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));
err = clGetPlatformIDs(numPlatforms, platforms, NULL);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to get OpenCL platform IDs. Error code %d\n", err);
  free(platforms);
  return std::vector<float> {};
}
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
cl_command_queue queue = clCreateCommandQueueWithProperties(context, device, 0, &err);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to create a command queue. Error code %d\n", err);
  clReleaseContext(context);
  return std::vector<float> {};
}
cl_mem bufferA = clCreateBuffer(context, CL_MEM_READ_ONLY, 24 * sizeof(float), NULL, &err);
cl_mem bufferC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, 24 * sizeof(float), NULL, &err);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to create buffers. Error code %d\n", err);
  clReleaseCommandQueue(queue);
  clReleaseContext(context);
  return std::vector<float> {};
}
cl_event transfer1;
err = clEnqueueWriteBuffer(queue, bufferA, CL_TRUE, 0, 24 * sizeof(float), tensor_onnxTanh_0, 0, NULL, &transfer1);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to write to bufferA. Error code %d\n", err);
  return std::vector<float> {};
}
cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, &err);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to create program. Error code %d\n", err);
  return std::vector<float> {};
}
err = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
if (err != CL_SUCCESS) {
  size_t log_size;
  clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
  char* log = (char*)malloc(log_size);
  clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
  fprintf(stderr, "Error: Failed to build program. Build log:\n%s\n", log);
  free(log);
  return std::vector<float> {};
}
cl_kernel kernel = clCreateKernel(program, "Tanh", &err);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to create kernel. Error code %d\n", err);
  return std::vector<float> {};
}
err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);
err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferC);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to set kernel arguments. Error code %d\n", err);
  return std::vector<float> {};
}
size_t globalSize = 24;
err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to enqueue kernel. Error code %d\n", err);
  return std::vector<float> {};
}
clFinish(queue);
err = clEnqueueReadBuffer(queue, bufferC, CL_TRUE, 0, 24 * sizeof(float), tensor_1, 0, NULL, NULL);
if (err != CL_SUCCESS) {
  fprintf(stderr, "Error: Failed to read bufferC. Error code %d\n", err);
  return std::vector<float> {};
}
clReleaseKernel(kernel);
clReleaseProgram(program);
clReleaseMemObject(bufferA);
clReleaseMemObject(bufferC);
clReleaseCommandQueue(queue);
clReleaseContext(context);
std::vector<float> ret(tensor_1, tensor_1 + 24);
return ret;
}
};   // end of Session
} 
#endif 
