//Code generated automatically by TMVA for Inference of Model file [Linear_16.onnx] at [Thu Mar 20 14:40:54 2025] 

#ifndef ROOT_TMVA_SOFIE_LINEAR_16
#define ROOT_TMVA_SOFIE_LINEAR_16

#include <algorithm>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_Linear_16{
namespace BLAS{
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
// initialized tensors
std::vector<float> fTensor_8weight = std::vector<float>(2500);
float * tensor_8weight = fTensor_8weight.data();
std::vector<float> fTensor_8bias = std::vector<float>(50);
float * tensor_8bias = fTensor_8bias.data();
std::vector<float> fTensor_4bias = std::vector<float>(50);
float * tensor_4bias = fTensor_4bias.data();
std::vector<float> fTensor_2weight = std::vector<float>(2500);
float * tensor_2weight = fTensor_2weight.data();
std::vector<float> fTensor_0bias = std::vector<float>(50);
float * tensor_0bias = fTensor_0bias.data();
std::vector<float> fTensor_12bias = std::vector<float>(50);
float * tensor_12bias = fTensor_12bias.data();
std::vector<float> fTensor_18bias = std::vector<float>(10);
float * tensor_18bias = fTensor_18bias.data();
std::vector<float> fTensor_14bias = std::vector<float>(50);
float * tensor_14bias = fTensor_14bias.data();
std::vector<float> fTensor_4weight = std::vector<float>(2500);
float * tensor_4weight = fTensor_4weight.data();
std::vector<float> fTensor_10weight = std::vector<float>(2500);
float * tensor_10weight = fTensor_10weight.data();
std::vector<float> fTensor_6bias = std::vector<float>(50);
float * tensor_6bias = fTensor_6bias.data();
std::vector<float> fTensor_18weight = std::vector<float>(500);
float * tensor_18weight = fTensor_18weight.data();
std::vector<float> fTensor_0weight = std::vector<float>(5000);
float * tensor_0weight = fTensor_0weight.data();
std::vector<float> fTensor_10bias = std::vector<float>(50);
float * tensor_10bias = fTensor_10bias.data();
std::vector<float> fTensor_2bias = std::vector<float>(50);
float * tensor_2bias = fTensor_2bias.data();
std::vector<float> fTensor_6weight = std::vector<float>(2500);
float * tensor_6weight = fTensor_6weight.data();
std::vector<float> fTensor_14weight = std::vector<float>(2500);
float * tensor_14weight = fTensor_14weight.data();
std::vector<float> fTensor_16weight = std::vector<float>(2500);
float * tensor_16weight = fTensor_16weight.data();
std::vector<float> fTensor_12weight = std::vector<float>(2500);
float * tensor_12weight = fTensor_12weight.data();
std::vector<float> fTensor_16bias = std::vector<float>(50);
float * tensor_16bias = fTensor_16bias.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
char* fIntermediateMemoryPool = new char[29440];


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor 22 with size 3200 bytes
float* tensor_22= reinterpret_cast<float*>(fIntermediateMemoryPool + 0);

 // Allocating memory for intermediate tensor 24 with size 3200 bytes
float* tensor_24= reinterpret_cast<float*>(fIntermediateMemoryPool + 3200);

 // Allocating memory for intermediate tensor 26 with size 3200 bytes
float* tensor_26= reinterpret_cast<float*>(fIntermediateMemoryPool + 6400);

 // Allocating memory for intermediate tensor 28 with size 3200 bytes
float* tensor_28= reinterpret_cast<float*>(fIntermediateMemoryPool + 9600);

 // Allocating memory for intermediate tensor 30 with size 3200 bytes
float* tensor_30= reinterpret_cast<float*>(fIntermediateMemoryPool + 12800);

 // Allocating memory for intermediate tensor 32 with size 3200 bytes
float* tensor_32= reinterpret_cast<float*>(fIntermediateMemoryPool + 16000);

 // Allocating memory for intermediate tensor 34 with size 3200 bytes
float* tensor_34= reinterpret_cast<float*>(fIntermediateMemoryPool + 19200);

 // Allocating memory for intermediate tensor 36 with size 3200 bytes
float* tensor_36= reinterpret_cast<float*>(fIntermediateMemoryPool + 22400);

 // Allocating memory for intermediate tensor 38 with size 3200 bytes
float* tensor_38= reinterpret_cast<float*>(fIntermediateMemoryPool + 25600);

 // Allocating memory for intermediate tensor 39 with size 640 bytes
float* tensor_39= reinterpret_cast<float*>(fIntermediateMemoryPool + 28800);

//--- declare and allocate the intermediate tensors
std::vector<float> fTensor_18biasbcast = std::vector<float>(160);
float * tensor_18biasbcast = fTensor_18biasbcast.data();
std::vector<float> fTensor_14biasbcast = std::vector<float>(800);
float * tensor_14biasbcast = fTensor_14biasbcast.data();
std::vector<float> fTensor_2biasbcast = std::vector<float>(800);
float * tensor_2biasbcast = fTensor_2biasbcast.data();
std::vector<float> fTensor_0biasbcast = std::vector<float>(800);
float * tensor_0biasbcast = fTensor_0biasbcast.data();
std::vector<float> fTensor_6biasbcast = std::vector<float>(800);
float * tensor_6biasbcast = fTensor_6biasbcast.data();
std::vector<float> fTensor_4biasbcast = std::vector<float>(800);
float * tensor_4biasbcast = fTensor_4biasbcast.data();
std::vector<float> fTensor_16biasbcast = std::vector<float>(800);
float * tensor_16biasbcast = fTensor_16biasbcast.data();
std::vector<float> fTensor_8biasbcast = std::vector<float>(800);
float * tensor_8biasbcast = fTensor_8biasbcast.data();
std::vector<float> fTensor_10biasbcast = std::vector<float>(800);
float * tensor_10biasbcast = fTensor_10biasbcast.data();
std::vector<float> fTensor_12biasbcast = std::vector<float>(800);
float * tensor_12biasbcast = fTensor_12biasbcast.data();


Session(std::string filename ="Linear_16.dat") {

//--- reading weights from file
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()) {
      throw std::runtime_error("tmva-sofie failed to open file " + filename + " for input weights");
   }
   std::string tensor_name;
   size_t length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_8weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_8weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2500 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_8weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_8weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_8bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_8bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_8bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_8bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_4bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_4bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_4bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_4bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_2weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_2weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2500 , read " + std::to_string(length) ;
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
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_0bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_0bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_12bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_12bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_12bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_12bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_18bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_18bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 10) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 10 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_18bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_18bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_14bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_14bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_14bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_14bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_4weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_4weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2500 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_4weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_4weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_10weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_10weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2500 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_10weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_10weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_6bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_6bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_6bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_6bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_18weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_18weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 500 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_18weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_18weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_0weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_0weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 5000) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 5000 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_0weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_0weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_10bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_10bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_10bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_10bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_2bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_2bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_2bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_2bias");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_6weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_6weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2500 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_6weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_6weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_14weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_14weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2500 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_14weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_14weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_16weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_16weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2500 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_16weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_16weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_12weight" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_12weight , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2500) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2500 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_12weight[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_12weight");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_16bias" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_16bias , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 50) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 50 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_16bias[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_16bias");
   }
   f.close();

//---- allocate the intermediate dynamic tensors
//--- broadcast bias tensor 0biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_0bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_0biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 2biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_2bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_2biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 4biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_4bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_4biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 6biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_6bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_6biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 8biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_8bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_8biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 10biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_10bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_10biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 12biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_12bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_12biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 14biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_14bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_14biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 16biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_16bias,{ 50 }, { 16 , 50 });
      std::copy(data, data + 800, tensor_16biasbcast);
      delete [] data;
   }
//--- broadcast bias tensor 18biasfor Gemm op
   {
      float * data = TMVA::Experimental::SOFIE::UTILITY::UnidirectionalBroadcast<float>(tensor_18bias,{ 10 }, { 16 , 10 });
      std::copy(data, data + 160, tensor_18biasbcast);
      delete [] data;
   }
}



std::vector<float> infer(float* tensor_input1){

//--------- Gemm
   char op_0_transA = 'n';
   char op_0_transB = 't';
   int op_0_m = 16;
   int op_0_n = 50;
   int op_0_k = 100;
   float op_0_alpha = 1;
   float op_0_beta = 1;
   int op_0_lda = 100;
   int op_0_ldb = 100;
   std::copy(tensor_0biasbcast, tensor_0biasbcast + 800, tensor_22);
   BLAS::sgemm_(&op_0_transB, &op_0_transA, &op_0_n, &op_0_m, &op_0_k, &op_0_alpha, tensor_0weight, &op_0_ldb, tensor_input1, &op_0_lda, &op_0_beta, tensor_22, &op_0_n);
   for (int id = 0; id < 800 ; id++){
      tensor_22[id] = ((tensor_22[id] > 0 )? tensor_22[id] : 0);
   }

//--------- Gemm
   char op_1_transA = 'n';
   char op_1_transB = 't';
   int op_1_m = 16;
   int op_1_n = 50;
   int op_1_k = 50;
   float op_1_alpha = 1;
   float op_1_beta = 1;
   int op_1_lda = 50;
   int op_1_ldb = 50;
   std::copy(tensor_2biasbcast, tensor_2biasbcast + 800, tensor_24);
   BLAS::sgemm_(&op_1_transB, &op_1_transA, &op_1_n, &op_1_m, &op_1_k, &op_1_alpha, tensor_2weight, &op_1_ldb, tensor_22, &op_1_lda, &op_1_beta, tensor_24, &op_1_n);
   for (int id = 0; id < 800 ; id++){
      tensor_24[id] = ((tensor_24[id] > 0 )? tensor_24[id] : 0);
   }

//--------- Gemm
   char op_2_transA = 'n';
   char op_2_transB = 't';
   int op_2_m = 16;
   int op_2_n = 50;
   int op_2_k = 50;
   float op_2_alpha = 1;
   float op_2_beta = 1;
   int op_2_lda = 50;
   int op_2_ldb = 50;
   std::copy(tensor_4biasbcast, tensor_4biasbcast + 800, tensor_26);
   BLAS::sgemm_(&op_2_transB, &op_2_transA, &op_2_n, &op_2_m, &op_2_k, &op_2_alpha, tensor_4weight, &op_2_ldb, tensor_24, &op_2_lda, &op_2_beta, tensor_26, &op_2_n);
   for (int id = 0; id < 800 ; id++){
      tensor_26[id] = ((tensor_26[id] > 0 )? tensor_26[id] : 0);
   }

//--------- Gemm
   char op_3_transA = 'n';
   char op_3_transB = 't';
   int op_3_m = 16;
   int op_3_n = 50;
   int op_3_k = 50;
   float op_3_alpha = 1;
   float op_3_beta = 1;
   int op_3_lda = 50;
   int op_3_ldb = 50;
   std::copy(tensor_6biasbcast, tensor_6biasbcast + 800, tensor_28);
   BLAS::sgemm_(&op_3_transB, &op_3_transA, &op_3_n, &op_3_m, &op_3_k, &op_3_alpha, tensor_6weight, &op_3_ldb, tensor_26, &op_3_lda, &op_3_beta, tensor_28, &op_3_n);
   for (int id = 0; id < 800 ; id++){
      tensor_28[id] = ((tensor_28[id] > 0 )? tensor_28[id] : 0);
   }

//--------- Gemm
   char op_4_transA = 'n';
   char op_4_transB = 't';
   int op_4_m = 16;
   int op_4_n = 50;
   int op_4_k = 50;
   float op_4_alpha = 1;
   float op_4_beta = 1;
   int op_4_lda = 50;
   int op_4_ldb = 50;
   std::copy(tensor_8biasbcast, tensor_8biasbcast + 800, tensor_30);
   BLAS::sgemm_(&op_4_transB, &op_4_transA, &op_4_n, &op_4_m, &op_4_k, &op_4_alpha, tensor_8weight, &op_4_ldb, tensor_28, &op_4_lda, &op_4_beta, tensor_30, &op_4_n);
   for (int id = 0; id < 800 ; id++){
      tensor_30[id] = ((tensor_30[id] > 0 )? tensor_30[id] : 0);
   }

//--------- Gemm
   char op_5_transA = 'n';
   char op_5_transB = 't';
   int op_5_m = 16;
   int op_5_n = 50;
   int op_5_k = 50;
   float op_5_alpha = 1;
   float op_5_beta = 1;
   int op_5_lda = 50;
   int op_5_ldb = 50;
   std::copy(tensor_10biasbcast, tensor_10biasbcast + 800, tensor_32);
   BLAS::sgemm_(&op_5_transB, &op_5_transA, &op_5_n, &op_5_m, &op_5_k, &op_5_alpha, tensor_10weight, &op_5_ldb, tensor_30, &op_5_lda, &op_5_beta, tensor_32, &op_5_n);
   for (int id = 0; id < 800 ; id++){
      tensor_32[id] = ((tensor_32[id] > 0 )? tensor_32[id] : 0);
   }

//--------- Gemm
   char op_6_transA = 'n';
   char op_6_transB = 't';
   int op_6_m = 16;
   int op_6_n = 50;
   int op_6_k = 50;
   float op_6_alpha = 1;
   float op_6_beta = 1;
   int op_6_lda = 50;
   int op_6_ldb = 50;
   std::copy(tensor_12biasbcast, tensor_12biasbcast + 800, tensor_34);
   BLAS::sgemm_(&op_6_transB, &op_6_transA, &op_6_n, &op_6_m, &op_6_k, &op_6_alpha, tensor_12weight, &op_6_ldb, tensor_32, &op_6_lda, &op_6_beta, tensor_34, &op_6_n);
   for (int id = 0; id < 800 ; id++){
      tensor_34[id] = ((tensor_34[id] > 0 )? tensor_34[id] : 0);
   }

//--------- Gemm
   char op_7_transA = 'n';
   char op_7_transB = 't';
   int op_7_m = 16;
   int op_7_n = 50;
   int op_7_k = 50;
   float op_7_alpha = 1;
   float op_7_beta = 1;
   int op_7_lda = 50;
   int op_7_ldb = 50;
   std::copy(tensor_14biasbcast, tensor_14biasbcast + 800, tensor_36);
   BLAS::sgemm_(&op_7_transB, &op_7_transA, &op_7_n, &op_7_m, &op_7_k, &op_7_alpha, tensor_14weight, &op_7_ldb, tensor_34, &op_7_lda, &op_7_beta, tensor_36, &op_7_n);
   for (int id = 0; id < 800 ; id++){
      tensor_36[id] = ((tensor_36[id] > 0 )? tensor_36[id] : 0);
   }

//--------- Gemm
   char op_8_transA = 'n';
   char op_8_transB = 't';
   int op_8_m = 16;
   int op_8_n = 50;
   int op_8_k = 50;
   float op_8_alpha = 1;
   float op_8_beta = 1;
   int op_8_lda = 50;
   int op_8_ldb = 50;
   std::copy(tensor_16biasbcast, tensor_16biasbcast + 800, tensor_38);
   BLAS::sgemm_(&op_8_transB, &op_8_transA, &op_8_n, &op_8_m, &op_8_k, &op_8_alpha, tensor_16weight, &op_8_ldb, tensor_36, &op_8_lda, &op_8_beta, tensor_38, &op_8_n);
   for (int id = 0; id < 800 ; id++){
      tensor_38[id] = ((tensor_38[id] > 0 )? tensor_38[id] : 0);
   }

//--------- Gemm
   char op_9_transA = 'n';
   char op_9_transB = 't';
   int op_9_m = 16;
   int op_9_n = 10;
   int op_9_k = 50;
   float op_9_alpha = 1;
   float op_9_beta = 1;
   int op_9_lda = 50;
   int op_9_ldb = 50;
   std::copy(tensor_18biasbcast, tensor_18biasbcast + 160, tensor_39);
   BLAS::sgemm_(&op_9_transB, &op_9_transA, &op_9_n, &op_9_m, &op_9_k, &op_9_alpha, tensor_18weight, &op_9_ldb, tensor_38, &op_9_lda, &op_9_beta, tensor_39, &op_9_n);
   std::vector<float> ret(tensor_39, tensor_39 + 160);
   return ret;
}
};   // end of Session
} //TMVA_SOFIE_Linear_16

#endif  // ROOT_TMVA_SOFIE_LINEAR_16
