// This macro runs the SOFIE parser on a custom Keras model
// 'CustomKerasModel.h5'

using namespace TMVA::Experimental;


void Keras_model_SOFIE(const char * modelFile = "CustomKerasModel.h5"){

     // check if the model file exists
    if (gSystem->AccessPathName(modelFile)) {
        Error("TMVA_SOFIE_RDataFrame", "Model file not found");
        return;
    }

    // parse the model
    SOFIE::RModel model = SOFIE::PyKeras::Parse(modelFile);

    TString modelHeaderFile = modelFile;
    modelHeaderFile.ReplaceAll(".h5",".hxx");

    //Generate the inference code
    model.Generate();
    model.OutputGenerated(std::string(modelHeaderFile));

    // copy include in the same directory
    std::cout << "Model header file is in the same directory" << std::endl;
}
