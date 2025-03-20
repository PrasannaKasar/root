//Code generated automatically by TMVA for Inference of Model file [Elu.onnx] at [Wed Mar 19 14:21:14 2025] 

#ifndef ROOT_TMVA_SOFIE_ELU
#define ROOT_TMVA_SOFIE_ELU

#include <vector>
#include "TMVA/SOFIE_common.hxx"

namespace TMVA_SOFIE_Elu{
struct Session {

//--- Allocating session memory pool to be used for allocating intermediate tensors
char* fIntermediateMemoryPool = new char[24];


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor output with size 24 bytes
float* tensor_output= reinterpret_cast<float*>(fIntermediateMemoryPool + 0);


Session(std::string = "") {
//---- allocate the intermediate dynamic tensors
}

std::vector<float> infer(float* tensor_input) {
   float op_0_alpha = 1;

//------ ELU 
   for (int id = 0; id < 6 ; id++){
      tensor_output[id] = ((tensor_input[id] >= 0 )? tensor_input[id] : op_0_alpha * std::exp(tensor_input[id]) - 1);
   }
   std::vector<float> ret(tensor_output, tensor_output + 6);
   return ret;
}
};   // end of Session
} //TMVA_SOFIE_Elu

#endif  // ROOT_TMVA_SOFIE_ELU
