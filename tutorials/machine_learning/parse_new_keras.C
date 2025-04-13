/// \file
/// \ingroup tutorial_ml
/// \notebook -nodraw
/// This macro provides a simple example for the parsing of Keras .h5 file
/// into RModel object and further generating the .hxx header files for inference.
///
/// \macro_code
/// \macro_output
/// \author Sanjiban Sengupta

using namespace TMVA::Experimental;

void parse_new_keras(const char * modelFile = "/home/prasanna/RootDevelopment/root/tutorials/machine_learning/new_keras_model.h5"){

    //Parsing the saved Keras .h5 file into RModel object
    
    SOFIE::RModel model = SOFIE::PyKeras::Parse(modelFile);

    TString modelHeaderFile = modelFile;
    modelHeaderFile.ReplaceAll(".h5",".hxx");

    //Generating inference code
    model.Generate();
    // generate output header. By default it will be modelName.hxx
    model.OutputGenerated(std::string(modelHeaderFile));

}
