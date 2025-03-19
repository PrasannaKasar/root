//Code generated automatically by TMVA for Inference of Model file [PyTorchModel.pt] at [Sun Mar 16 05:19:41 2025] 

#ifndef ROOT_TMVA_SOFIE_PYTORCHMODEL
#define ROOT_TMVA_SOFIE_PYTORCHMODEL

#include <algorithm>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_PyTorchModel{
namespace BLAS{
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
// initialized tensors
std::vector<float> fTensor_2bias = std::vector<float>(8);
float * tensor_2bias = fTensor_2bias.data();
std::vector<float> fTensor_0weight = std::vector<float>(512);
float * tensor_0weight = fTensor_0weight.data();
std::vector<float> fTensor_2weight = std::vector<float>(128);
float * tensor_2weight = fTensor_2weight.data();
std::vector<float> fTensor_0bias = std::vector<float>(16);
float * tensor_0bias = fTensor_0bias.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
char* fIntermediateMemoryPool = new char[384];


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor input0 with size 128 bytes
float* tensor_input0= reinterpret_cast<float*>(fIntermediateMemoryPool + 0);

 // Allocating memory for intermediate tensor result with size 128 bytes
float* tensor_result= reinterpret_cast<float*>(fIntermediateMemoryPool + 128);

 // Allocating memory for intermediate tensor input2 with size 64 bytes
float* tensor_input2= reinterpret_cast<float*>(fIntermediateMemoryPool + 256);

 // Allocating memory for intermediate tensor result3 with size 64 bytes
float* tensor_result3= reinterpret_cast<float*>(fIntermediateMemoryPool + 320);

//--- declare and allocate the intermediate tensors
std::vector<float> fTensor_2biasbcast = std::vector<float>(16);
float * tensor_2biasbcast = fTensor_2biasbcast.data();
std::vector<float> fTensor_0biasbcast = std::vector<float>(32);
float * tensor_0biasbcast = fTensor_0biasbcast.data();


Session(std::string filename ="PyTorchModel.dat") {

//--- reading weights from file
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()) {
      throw std::runtime_error("tmva-sofie failed to open file " + filename + " for input weights");
   }
   std::string tensor_name;
   size_t length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_2bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_2bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 8) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 8 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_2bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_2bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 512) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 512 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_0weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_0weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_2weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_2weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 128) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 128 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_2weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_2weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_0bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_0bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 16) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 16 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_0bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_0bias");
   }
   f.close();

//---- allocate the intermediate dynamic tensors
//--- broadcast bias tensor 0biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_0bias,{ 16 }, { 2 , 16 });
      std::copy(data, data + 32, tensor_0biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 2biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_2bias,{ 8 }, { 2 , 8 });
      std::copy(data, data + 16, tensor_2biasbcast);
      delete [] data;
   }
}

std::vector<float> infer(float* tensor_input1){

//--------- Gemm
   char op_0_transA = 'n';
   char op_0_transB = 't';
   int op_0_m = 2;
   int op_0_n = 16;
   int op_0_k = 32;
   float op_0_alpha = 1;
   float op_0_beta = 1;
   int op_0_lda = 32;
   int op_0_ldb = 32;
   std::copy(tensor_0biasbcast, tensor_0biasbcast + 32, tensor_input0);
   BLAS::sgemm_(&op_0_transB, &op_0_transA, &op_0_n, &op_0_m, &op_0_k, &op_0_alpha, tensor_0weight, &op_0_ldb, tensor_input1, &op_0_lda, &op_0_beta, tensor_input0, &op_0_n);

//------ RELU
   for (int id = 0; id < 32 ; id++){
      tensor_result[id] = ((tensor_input0[id] > 0 )? tensor_input0[id] : 0);
   }

//--------- Gemm
   char op_2_transA = 'n';
   char op_2_transB = 't';
   int op_2_m = 2;
   int op_2_n = 8;
   int op_2_k = 16;
   float op_2_alpha = 1;
   float op_2_beta = 1;
   int op_2_lda = 16;
   int op_2_ldb = 16;
   std::copy(tensor_2biasbcast, tensor_2biasbcast + 16, tensor_input2);
   BLAS::sgemm_(&op_2_transB, &op_2_transA, &op_2_n, &op_2_m, &op_2_k, &op_2_alpha, tensor_2weight, &op_2_ldb, tensor_result, &op_2_lda, &op_2_beta, tensor_input2, &op_2_n);

//------ RELU
   for (int id = 0; id < 16 ; id++){
      tensor_result3[id] = ((tensor_input2[id] > 0 )? tensor_input2[id] : 0);
   }
   std::vector<float> ret(tensor_result3, tensor_result3 + 16);
   return ret;
}
};   // end of Session
} //TMVA_SOFIE_PyTorchModel

#endif  // ROOT_TMVA_SOFIE_PYTORCHMODEL
