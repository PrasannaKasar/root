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
      inputFile = "/home/prasanna/RootDevelopment/root/tmva/sofie/test/input_models/Tanh.onnx";

    // Create an instance of the RModelParser_ONNX class
    // Create an instance of RModelParser_ONNX
    TMVA::Experimental::SOFIE::RModelParser_ONNX parser;

    // Load the ONNX model (Tanh.onnx)
    auto model = parser.LoadModel(inputFile);

    // Get the graph from the model
    const onnx::GraphProto& graph = model->graph();

    // You will need to access the nodes from the graph
    std::vector<size_t> nodes;
    for (size_t i = 0; i < graph.node_size(); ++i) {
        nodes.push_back(i);  // Store node indices for parsing
    }

    // Now you can parse the operators
    for (size_t i = 0; i < nodes.size(); ++i) {
        std::unique_ptr<ROperator> operator = parser.ParseOperator(i, graph, nodes);

        // Print the parsed operator information (example)
        std::cout << "Parsed operator: " << operator->GetName() << std::endl;
    }
}
