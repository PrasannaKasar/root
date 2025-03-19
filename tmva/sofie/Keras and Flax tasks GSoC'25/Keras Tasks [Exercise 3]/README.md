# Exercise 3 – Play with the SOFIE Keras Parser and FLAX Library

## Overview

In this exercise, we explore the integration between SOFIE's Keras Parser and the FLAX library. SOFIE provides a Keras Parser capable of translating models trained in TensorFlow/Keras into its own Intermediate Representation (IR). The task involves generating a Keras model, parsing it using the SOFIE Keras Parser, and converting it into a format compatible with FLAX for further use.

## Key Steps

1. **Generate a Keras Model:**
   - We first create a Keras model using TensorFlow/Keras. This model is saved as `CustomKerasModel.h5`.
   
2. **Parse the Keras Model:**
   - After saving the model, we parse it using the SOFIE Keras Parser. This step is performed by running the `Parse_Keras_Model.C` macro in the root command line with the `.x Parse_Keras_Model` command.
   
3. **Generate Header File:**
   - The parser translates the saved Keras model into an Intermediate Representation (IR) and generates a header file, `CustomKerasModel.hxx`, which contains the model's structure and relevant information.

## Objective

The primary objective of this exercise is to:
- Familiarize with SOFIE's Keras Parser and its capabilities to translate Keras models.
- Explore the integration between SOFIE and the FLAX library by understanding how Keras models can be transformed into formats that are usable within FLAX.

## Process

- **Keras Model Generation:** A custom model is created using Keras, which is then saved to a file.
- **Parsing with SOFIE:** The saved model is parsed using SOFIE’s Keras Parser to translate the model into its IR.
- **Header File Generation:** After parsing, the model's structure is exported as a header file for further integration with FLAX or other frameworks.

## Conclusion

This exercise demonstrates the process of translating Keras models into a format that can be used by other deep learning libraries like FLAX. By generating the header file (`CustomKerasModel.hxx`), the model is now ready for further use or integration with SOFIE-based systems.