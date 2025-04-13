//Code generated automatically by TMVA for Inference of Model file [ConvWithoutPadding.onnx] at [Fri Mar 21 22:26:53 2025] 

#ifndef ROOT_TMVA_SOFIE_CONVWITHOUTPADDING
#define ROOT_TMVA_SOFIE_CONVWITHOUTPADDING

#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>

namespace TMVA_SOFIE_ConvWithoutPadding{
namespace BLAS{
	extern "C" void saxpy_(const int * n, const float * alpha, const float * x,
	                         const int * incx, float * y, const int * incy);
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
}//BLAS
struct Session {
// initialized tensors
std::vector<float> fTensor_W = std::vector<float>(9);
float * tensor_W = fTensor_W.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
char* fIntermediateMemoryPool = new char[396];


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor y with size 36 bytes
float* tensor_y= reinterpret_cast<float*>(fIntermediateMemoryPool + 0);

 // Allocating memory for intermediate tensor x_f with size 36 bytes
float* tensor_x_f= reinterpret_cast<float*>(fIntermediateMemoryPool + 36);

 // Allocating memory for intermediate tensor x_xcol with size 324 bytes
float* tensor_x_xcol= reinterpret_cast<float*>(fIntermediateMemoryPool + 72);


Session(std::string filename ="ConvWithoutPadding.dat") {

//--- reading weights from file
   std::ifstream f;
   f.open(filename);
   if (!f.is_open()) {
      throw std::runtime_error("tmva-sofie failed to open file " + filename + " for input weights");
   }
   std::string tensor_name;
   size_t length;
   f >> tensor_name >> length;
   if (tensor_name != "tensor_W" ) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor name; expected name is tensor_W , read " + tensor_name;
      throw std::runtime_error(err_msg);
    }
   if (length != 9) {
      std::string err_msg = "TMVA-SOFIE failed to read the correct tensor size; expected size is 9 , read " + std::to_string(length) ;
      throw std::runtime_error(err_msg);
    }
   for (size_t i = 0; i < length; ++i)
      f >> tensor_W[i];
   if (f.fail()) {
      throw std::runtime_error("TMVA-SOFIE failed to read the values for tensor tensor_W");
   }
   f.close();

//---- allocate the intermediate dynamic tensors
}



std::vector<float> infer(float* tensor_x){

//----  operator Conv op_0
   for (std::size_t oc = 0; oc < 1; oc++) {
      for (std::size_t ic = 0; ic < 1; ic++) {
         for (std::size_t kh = 0; kh < 3; kh++) {
            for (std::size_t kw = 0; kw < 3; kw++) {
               tensor_x_f[oc * 9 + ic * 9 + kh * 3 + kw * 1  ] = tensor_W[oc * 9 + ic * 9 + kh * 3 + kw ];
            }
         }
      }
   }
   char op_0_transA = 'N';
   char op_0_transB = 'N';
   int op_0_m = 9;
   int op_0_n = 1;
   int op_0_k = 9;
   float op_0_alpha = 1.0;
   float op_0_beta = 0.0;
   for (size_t n = 0; n < 1; n++) {
      size_t out_offset = n * 9;
      size_t x_offset = n * 25;
      TMVA::Experimental::SOFIE::UTILITY::Im2col<float>(tensor_x + x_offset,1,5,5,3,3,0,0,1,1,1,1,tensor_x_xcol);

       BLAS::sgemm_(&op_0_transA, &op_0_transB, &op_0_m, &op_0_n, &op_0_k, &op_0_alpha, tensor_x_xcol, &op_0_m,
         tensor_x_f, &op_0_k, &op_0_beta, tensor_y + out_offset, &op_0_m);
   }
   std::vector<float> ret(tensor_y, tensor_y + 9);
   return ret;
}
};   // end of Session
} //TMVA_SOFIE_ConvWithoutPadding

#endif  // ROOT_TMVA_SOFIE_CONVWITHOUTPADDING
