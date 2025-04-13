#ifndef TMVA_SOFIE_ROPERATOR_Tanh
#define TMVA_SOFIE_ROPERATOR_Tanh

#include "TMVA/SOFIE_common.hxx"
#include "TMVA/ROperator.hxx"
#include "TMVA/RModel.hxx"

#include <sstream>

namespace TMVA{
namespace Experimental{
namespace SOFIE{

template <typename T>
class ROperator_Tanh final : public ROperator
{

private:

   std::string fNX;
   std::string fNY;
   std::vector<size_t> fShape;

public:
   ROperator_Tanh(){}
   ROperator_Tanh(std::string nameX, std::string nameY):
      fNX(UTILITY::Clean_name(nameX)), fNY(UTILITY::Clean_name(nameY)){
         fInputTensorNames = { fNX };
         fOutputTensorNames = { fNY };
      }

   std::vector<ETensorType> TypeInference(std::vector<ETensorType> input) override {
      return input;
   }

   std::vector<std::vector<size_t>> ShapeInference(std::vector<std::vector<size_t>> input) override {
      auto ret = input; //suggest copy to compiler
      return ret;
   }

   void Initialize(RModel& model) override {
       //input must be a graph input, or already initialized intermediate tensor
      if (model.CheckIfTensorAlreadyExist(fNX) == false){
        throw std::runtime_error("TMVA SOFIE Tanh Op Input Tensor is not found in model");
      }
      fShape = model.GetTensorShape(fNX);
      model.AddIntermediateTensor(fNY, model.GetTensorType(fNX), fShape);

   }


   std::string Generate(std::string OpName) override {
      OpName = "op_" + OpName;
      if (fShape.empty()) {
         throw std::runtime_error("TMVA SOFIE Tanh operator called to Generate without being initialized first");
      }
      std::stringstream out;
      size_t length = ConvertShapeToLength(fShape);
      out << "\n//------ TANH\n";
      out << SP << "for (int id = 0; id < " << length << " ; id++){\n";
      out << SP << SP << "tensor_" << fNY << "[id] = std::tanh(tensor_" << fNX << "[id]);\n";
      out << SP << "}\n";
      return out.str();
   }
   
   std::string GetLength() override {
      size_t length = ConvertShapeToLength(fShape);
      return std::to_string(length); 
   }

   std::string GenerateGPUOpenCL(std::string OpName) override {

      OpName = "Tanh";
  
      if (fShape.empty()) {
          throw std::runtime_error("OpenCL error: TMVA SOFIE Operator Tanh called to Generate without being initialized first");
      }
  
      std::stringstream out;
      size_t length = ConvertShapeToLength(fShape);
  
      out << "\n//------ TANH\n";
      out << "const char* kernelSource = \"__kernel void " << OpName 
          << "(__global const float* A, __global float* C) {\\n\"\n";
      out << "\"  int id = get_global_id(0);\\n\"\n";
      out << "\"  if (id < " << length << ") {\\n\"\n";
      out << "\"    C[id] = tanh(A[id]);\\n\"\n";
      out << "\"  }\\n\"\n";
      out << "\"}\";\n\n";
      
      out << "cl_int err;\n";
      out << "cl_uint numPlatforms;\n";
      out << "err = clGetPlatformIDs(0, NULL, &numPlatforms);\n";
      out << "if (err != CL_SUCCESS || numPlatforms == 0) {\n";
      out << "  fprintf(stderr, \"Error: Failed to find any OpenCL platforms. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "cl_platform_id* platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));\n";
      out << "err = clGetPlatformIDs(numPlatforms, platforms, NULL);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to get OpenCL platform IDs. Error code %d\\n\", err);\n";
      out << "  free(platforms);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "cl_platform_id platform = platforms[0];\n";
      out << "free(platforms);\n";
      
      out << "cl_device_id device;\n";
      out << "err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_DEFAULT, 1, &device, NULL);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to get an OpenCL device. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to create a context. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "cl_command_queue queue = clCreateCommandQueueWithProperties(context, device, 0, &err);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to create a command queue. Error code %d\\n\", err);\n";
      out << "  clReleaseContext(context);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "cl_mem bufferA = clCreateBuffer(context, CL_MEM_READ_ONLY, " << length << " * sizeof(float), NULL, &err);\n";
      out << "cl_mem bufferC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, " << length << " * sizeof(float), NULL, &err);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to create buffers. Error code %d\\n\", err);\n";
      out << "  clReleaseCommandQueue(queue);\n";
      out << "  clReleaseContext(context);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "cl_event transfer1;\n";
      out << "err = clEnqueueWriteBuffer(queue, bufferA, CL_TRUE, 0, " << length << " * sizeof(float), tensor_onnxTanh_0, 0, NULL, &transfer1);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to write to bufferA. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, &err);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to create program. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "err = clBuildProgram(program, 1, &device, NULL, NULL, NULL);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  size_t log_size;\n";
      out << "  clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);\n";
      out << "  char* log = (char*)malloc(log_size);\n";
      out << "  clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);\n";
      out << "  fprintf(stderr, \"Error: Failed to build program. Build log:\\n%s\\n\", log);\n";
      out << "  free(log);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "cl_kernel kernel = clCreateKernel(program, \"" << OpName << "\", &err);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to create kernel. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);\n";
      out << "err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferC);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to set kernel arguments. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "size_t globalSize = " << length << ";\n";
      out << "err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to enqueue kernel. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "clFinish(queue);\n";
      
      out << "err = clEnqueueReadBuffer(queue, bufferC, CL_TRUE, 0, " << length << " * sizeof(float), tensor_1, 0, NULL, NULL);\n";
      out << "if (err != CL_SUCCESS) {\n";
      out << "  fprintf(stderr, \"Error: Failed to read bufferC. Error code %d\\n\", err);\n";
      out << "  return std::vector<float> {};\n";
      out << "}\n";
      
      out << "clReleaseKernel(kernel);\n";
      out << "clReleaseProgram(program);\n";
      out << "clReleaseMemObject(bufferA);\n";
      out << "clReleaseMemObject(bufferC);\n";
      out << "clReleaseCommandQueue(queue);\n";
      out << "clReleaseContext(context);\n";
      
      out << "std::vector<float> ret(tensor_1, tensor_1 + " << length << ");\n";
      out << "return ret;\n";   
      out << "\"}\";\n";
  
      return out.str();
  } 

   std::vector<std::string> GetStdLibs() override { return { std::string("cmath") };}
};

}//SOFIE
}//Experimental
}//TMVA


#endif //TMVA_SOFIE_ROPERATOR_Tanh