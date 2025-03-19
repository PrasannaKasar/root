/// \file
/// \ingroup tutorial_ml
/// \notebook -nodraw
/// This macro provides a simple example for the parsing of ONNX files into
/// RModel object and further generating the .hxx header files for inference.
///
/// \macro_code
/// \macro_output
/// \author Sanjiban Sengupta

using namespace TMVA::Experimental;

// /home/prasanna/RootDevelopment/root/tmva/sofie/test/input_models/Linear_16.onnx
// /home/prasanna/root/tmva/sofie/test/input_models/Linear_16.onnx


void parse_onnx(std::string inputFile = ""){
   if (inputFile.empty() )
      inputFile = "/home/prasanna/RootDevelopment/root/tmva/sofie/test/input_models/Linear_16.onnx";

    //   std::printf("2");

    //Creating parser object to parse ONNX files
    SOFIE::RModelParser_ONNX parser;
    SOFIE::RModel model = parser.Parse(inputFile, true);

    //Generating inference code
    model.GenerateGPUOpenCL();
    // write the code in a file (by default Linear_16.hxx and Linear_16.dat
    model.OutputGenerated();

    //Printing required input tensors
    model.PrintRequiredInputTensors();

    //Printing initialized tensors (weights)
    std::cout<<"\n\n";
    model.PrintInitializedTensors();

    //Printing intermediate tensors
    std::cout<<"\n\n";
    model.PrintIntermediateTensors();

    //Checking if tensor already exist in model
    std::cout<<"\n\nTensor \"16weight\" already exist: "<<std::boolalpha<<model.CheckIfTensorAlreadyExist("16weight")<<"\n\n";
    std::vector<size_t> tensorShape = model.GetTensorShape("16weight");
    std::cout<<"Shape of tensor \"16weight\": ";
    for(auto& it:tensorShape){
        std::cout<<it<<",";
    }
    std::cout<<"\n\nData type of tensor \"16weight\": ";
    SOFIE::ETensorType tensorType = model.GetTensorType("16weight");
    std::cout<<SOFIE::ConvertTypeToString(tensorType);

    //Printing generated inference code
    std::cout<<"\n\n";
    model.PrintGenerated();
}
