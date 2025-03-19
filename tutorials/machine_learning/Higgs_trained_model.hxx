//Code generated automatically by TMVA for Inference of Model file [Higgs_trained_model.h5] at [Thu Mar 13 12:04:18 2025] 

#ifndef ROOT_TMVA_SOFIE_HIGGS_TRAINED_MODEL
#define ROOT_TMVA_SOFIE_HIGGS_TRAINED_MODEL

#include <algorithm>
#include <cmath>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_Higgs_trained_model{
namespace BLAS{
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
// initialized tensors
std::vector<float> fTensor_dense_4kernel0 = std::vector<float>(128);
float * tensor_dense_4kernel0 = fTensor_dense_4kernel0.data();
std::vector<float> fTensor_dense_3bias0 = std::vector<float>(64);
float * tensor_dense_3bias0 = fTensor_dense_3bias0.data();
std::vector<float> fTensor_dense_3kernel0 = std::vector<float>(4096);
float * tensor_dense_3kernel0 = fTensor_dense_3kernel0.data();
std::vector<float> fTensor_dense_2kernel0 = std::vector<float>(4096);
float * tensor_dense_2kernel0 = fTensor_dense_2kernel0.data();
std::vector<float> fTensor_dense_1bias0 = std::vector<float>(64);
float * tensor_dense_1bias0 = fTensor_dense_1bias0.data();
std::vector<float> fTensor_dense_4bias0 = std::vector<float>(2);
float * tensor_dense_4bias0 = fTensor_dense_4bias0.data();
std::vector<float> fTensor_dense_1kernel0 = std::vector<float>(4096);
float * tensor_dense_1kernel0 = fTensor_dense_1kernel0.data();
std::vector<float> fTensor_densebias0 = std::vector<float>(64);
float * tensor_densebias0 = fTensor_densebias0.data();
std::vector<float> fTensor_dense_2bias0 = std::vector<float>(64);
float * tensor_dense_2bias0 = fTensor_dense_2bias0.data();
std::vector<float> fTensor_densekernel0 = std::vector<float>(448);
float * tensor_densekernel0 = fTensor_densekernel0.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
char* fIntermediateMemoryPool = new char[2064];


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor denseDense with size 256 bytes
float* tensor_denseDense= reinterpret_cast<float*>(fIntermediateMemoryPool + 0);

 // Allocating memory for intermediate tensor denseRelu0 with size 256 bytes
float* tensor_denseRelu0= reinterpret_cast<float*>(fIntermediateMemoryPool + 256);

 // Allocating memory for intermediate tensor dense_1Dense with size 256 bytes
float* tensor_dense_1Dense= reinterpret_cast<float*>(fIntermediateMemoryPool + 512);

 // Allocating memory for intermediate tensor dense_1Relu0 with size 256 bytes
float* tensor_dense_1Relu0= reinterpret_cast<float*>(fIntermediateMemoryPool + 768);

 // Allocating memory for intermediate tensor dense_2Dense with size 256 bytes
float* tensor_dense_2Dense= reinterpret_cast<float*>(fIntermediateMemoryPool + 1024);

 // Allocating memory for intermediate tensor dense_2Relu0 with size 256 bytes
float* tensor_dense_2Relu0= reinterpret_cast<float*>(fIntermediateMemoryPool + 1280);

 // Allocating memory for intermediate tensor dense_3Dense with size 256 bytes
float* tensor_dense_3Dense= reinterpret_cast<float*>(fIntermediateMemoryPool + 1536);

 // Allocating memory for intermediate tensor dense_3Relu0 with size 256 bytes
float* tensor_dense_3Relu0= reinterpret_cast<float*>(fIntermediateMemoryPool + 1792);

 // Allocating memory for intermediate tensor dense_4Dense with size 8 bytes
float* tensor_dense_4Dense= reinterpret_cast<float*>(fIntermediateMemoryPool + 2048);

 // Allocating memory for intermediate tensor dense_4Sigmoid0 with size 8 bytes
float* tensor_dense_4Sigmoid0= reinterpret_cast<float*>(fIntermediateMemoryPool + 2056);


Session(std::string filename ="Higgs_trained_model.dat") {

//--- reading weights from file
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()) {
      throw std::runtime_error("tmva-sofie failed to open file " + filename + " for input weights");
   }
   std::string tensor_name;
   size_t length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_dense_4kernel0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_dense_4kernel0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 128) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 128 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_dense_4kernel0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_dense_4kernel0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_dense_3bias0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_dense_3bias0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 64) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 64 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_dense_3bias0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_dense_3bias0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_dense_3kernel0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_dense_3kernel0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 4096) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 4096 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_dense_3kernel0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_dense_3kernel0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_dense_2kernel0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_dense_2kernel0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 4096) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 4096 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_dense_2kernel0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_dense_2kernel0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_dense_1bias0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_dense_1bias0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 64) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 64 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_dense_1bias0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_dense_1bias0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_dense_4bias0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_dense_4bias0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 2) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 2 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_dense_4bias0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_dense_4bias0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_dense_1kernel0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_dense_1kernel0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 4096) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 4096 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_dense_1kernel0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_dense_1kernel0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_densebias0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_densebias0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 64) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 64 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_densebias0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_densebias0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_dense_2bias0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_dense_2bias0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 64) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 64 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_dense_2bias0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_dense_2bias0");
   }
   f >> tensor_name >> length;
   if (tensor_name != "tensor_densekernel0" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_densekernel0 , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 448) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 448 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_densekernel0[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_densekernel0");
   }
   f.close();

//---- allocate the intermediate dynamic tensors
}

std::vector<float> infer(float* tensor_dense_input){

//--------- Gemm
   char op_0_transA = 'n';
   char op_0_transB = 'n';
   int op_0_m = 1;
   int op_0_n = 64;
   int op_0_k = 7;
   float op_0_alpha = 1;
   float op_0_beta = 1;
   int op_0_lda = 7;
   int op_0_ldb = 64;
   std::copy(tensor_densebias0, tensor_densebias0 + 64, tensor_denseDense);
   BLAS::sgemm_(&op_0_transB, &op_0_transA, &op_0_n, &op_0_m, &op_0_k, &op_0_alpha, tensor_densekernel0, &op_0_ldb, tensor_dense_input, &op_0_lda, &op_0_beta, tensor_denseDense, &op_0_n);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_denseRelu0[id] = ((tensor_denseDense[id] > 0 )? tensor_denseDense[id] : 0);
   }

//--------- Gemm
   char op_2_transA = 'n';
   char op_2_transB = 'n';
   int op_2_m = 1;
   int op_2_n = 64;
   int op_2_k = 64;
   float op_2_alpha = 1;
   float op_2_beta = 1;
   int op_2_lda = 64;
   int op_2_ldb = 64;
   std::copy(tensor_dense_1bias0, tensor_dense_1bias0 + 64, tensor_dense_1Dense);
   BLAS::sgemm_(&op_2_transB, &op_2_transA, &op_2_n, &op_2_m, &op_2_k, &op_2_alpha, tensor_dense_1kernel0, &op_2_ldb, tensor_denseRelu0, &op_2_lda, &op_2_beta, tensor_dense_1Dense, &op_2_n);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_dense_1Relu0[id] = ((tensor_dense_1Dense[id] > 0 )? tensor_dense_1Dense[id] : 0);
   }

//--------- Gemm
   char op_4_transA = 'n';
   char op_4_transB = 'n';
   int op_4_m = 1;
   int op_4_n = 64;
   int op_4_k = 64;
   float op_4_alpha = 1;
   float op_4_beta = 1;
   int op_4_lda = 64;
   int op_4_ldb = 64;
   std::copy(tensor_dense_2bias0, tensor_dense_2bias0 + 64, tensor_dense_2Dense);
   BLAS::sgemm_(&op_4_transB, &op_4_transA, &op_4_n, &op_4_m, &op_4_k, &op_4_alpha, tensor_dense_2kernel0, &op_4_ldb, tensor_dense_1Relu0, &op_4_lda, &op_4_beta, tensor_dense_2Dense, &op_4_n);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_dense_2Relu0[id] = ((tensor_dense_2Dense[id] > 0 )? tensor_dense_2Dense[id] : 0);
   }

//--------- Gemm
   char op_6_transA = 'n';
   char op_6_transB = 'n';
   int op_6_m = 1;
   int op_6_n = 64;
   int op_6_k = 64;
   float op_6_alpha = 1;
   float op_6_beta = 1;
   int op_6_lda = 64;
   int op_6_ldb = 64;
   std::copy(tensor_dense_3bias0, tensor_dense_3bias0 + 64, tensor_dense_3Dense);
   BLAS::sgemm_(&op_6_transB, &op_6_transA, &op_6_n, &op_6_m, &op_6_k, &op_6_alpha, tensor_dense_3kernel0, &op_6_ldb, tensor_dense_2Relu0, &op_6_lda, &op_6_beta, tensor_dense_3Dense, &op_6_n);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_dense_3Relu0[id] = ((tensor_dense_3Dense[id] > 0 )? tensor_dense_3Dense[id] : 0);
   }

//--------- Gemm
   char op_8_transA = 'n';
   char op_8_transB = 'n';
   int op_8_m = 1;
   int op_8_n = 2;
   int op_8_k = 64;
   float op_8_alpha = 1;
   float op_8_beta = 1;
   int op_8_lda = 64;
   int op_8_ldb = 2;
   std::copy(tensor_dense_4bias0, tensor_dense_4bias0 + 2, tensor_dense_4Dense);
   BLAS::sgemm_(&op_8_transB, &op_8_transA, &op_8_n, &op_8_m, &op_8_k, &op_8_alpha, tensor_dense_4kernel0, &op_8_ldb, tensor_dense_3Relu0, &op_8_lda, &op_8_beta, tensor_dense_4Dense, &op_8_n);
	for (int id = 0; id < 2 ; id++){
		tensor_dense_4Sigmoid0[id] = 1 / (1 + std::exp( - tensor_dense_4Dense[id]));
	}
   std::vector<float> ret(tensor_dense_4Sigmoid0, tensor_dense_4Sigmoid0 + 2);
   return ret;
}
};   // end of Session
} //TMVA_SOFIE_Higgs_trained_model

#endif  // ROOT_TMVA_SOFIE_HIGGS_TRAINED_MODEL
