/// \file
/// \ingroup tutorial_ml
/// \notebook -nodraw
/// This macro provides a simple example for the parsing of ONNX files into
/// RModel object and further generating the .hxx header files for inference.
///
/// \macro_code
/// \macro_output

using namespace TMVA::Experimental;

void parse_onnx_op_tanh(std::string inputFile = ""){
   if (inputFile.empty() )
      inputFile = "/home/prasanna/RootDevelopment/root/tmva/sofie/test/input_models/Tanh.onnx";

    //   std::printf("2");

    //Creating parser object to parse ONNX files
    SOFIE::RModelParser_ONNX parser;
    SOFIE::RModel model = parser.Parse(inputFile, true);

    //Generating inference code
    model.GenerateGPUOpenCL();
    model.OutputGenerated();
}
