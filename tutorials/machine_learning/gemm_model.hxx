#ifndef ROOT_TMVA_SOFIE_GEMM_MODEL_GPU 
#define ROOT_TMVA_SOFIE_GEMM_MODEL_GPU 
#include <cmath> 
#include <vector> 
#include "TMVA/SOFIE_common.hxx" 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <CL/cl.h> 
#include <clBLAS.h> 
namespace TMVA_SOFIE_gemm_model_GPU { 
struct Session {

//--- Allocating session memory pool to be used for allocating intermediate tensors
char* fIntermediateMemoryPool = new char[96];


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor output with size 96 bytes
float* tensor_output= reinterpret_cast<float*>(fIntermediateMemoryPool + 0);


Session(std::string filename ="gemm_model.dat") {

//--- reading weights from file

//---- allocate the intermediate dynamic tensors
}



std::vector<float> infer(float* tensor_A,float* tensor_B,float* tensor_C){

//--------- Gemm
   printf("\nInfering Gemm operator on OpenCL...");
   char op_0_transA = 'n';
   char op_0_transB = 'n';
   int op_0_m = 4;
   int op_0_n = 6;
   int op_0_k = 5;
   float op_0_alpha = 2;
   float op_0_beta = 3;
   int op_0_lda = 5;
   int op_0_ldb = 6;
   std::copy(tensor_C, tensor_C + 24, tensor_output);
   cl_platform_id platform = NULL; 
   cl_device_id device = NULL; 
   cl_context context = NULL; 
   cl_command_queue queue = NULL; 
   cl_int err; 
   err = clGetPlatformIDs(1, &platform, NULL); 
   err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL); 
   context = clCreateContext(NULL, 1, &device, NULL, NULL, &err); 
   queue = clCreateCommandQueue(context, device, 0, &err); 
   err = clblasSetup(); 
   cl_mem bufA = clCreateBuffer(context, CL_MEM_READ_ONLY, 4 * 5 * sizeof(float), tensor_A, &err);
   cl_mem bufB = clCreateBuffer(context, CL_MEM_READ_ONLY, 5 * 6 * sizeof(float), tensor_B, &err);
   cl_mem bufC = clCreateBuffer(context, CL_MEM_READ_ONLY, 4 * 6 * sizeof(float), tensor_output, &err);
   err = clblasSgemm(clblasRowMajor, clblasNoTrans, clblasNoTrans, 4, 6, 5, op_0_alpha, bufA, 0, 5, bufB, 0, 6, op_0_beta, bufC, 0, 6, 1, &queue, 0, NULL, NULL); 
   err = clFinish(queue); 
   err = clEnqueueReadBuffer(queue, bufC, CL_TRUE, 0, 4 * 6 * sizeof(float), tensor_output , 0, NULL, NULL); 
   clReleaseMemObject(bufA); 
   clReleaseMemObject(bufB); 
   clReleaseMemObject(bufC); 
   clblasTeardown(); 
   clReleaseCommandQueue(queue); 
   clReleaseContext(context); 
   
std::vector<float> ret(tensor_output, tensor_output + 24); 
   return ret; 
}
};   // end of Session
} 
#endif 
