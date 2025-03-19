# Model Configuration Extractor for FLAX

## Overview

This repository contains a Python function `get_model_config` that extracts and returns the configuration of a FLAX model as a dictionary. The function is capable of handling nested layers within the model, making it suitable for complex architectures where layers contain other sub-layers (e.g., an encoder layer with `linear1` and `linear2` as sub-layers).

## Key Features

- **Recursive Parsing:** The function can recursively process nested layers within the model and extract detailed information for each layer, including sub-layers.
- **Layer Information:** For each layer, the function gathers important details, including the layer name, type, input/output dimensions, number of parameters, and data type.
- **Model Summary:** The function also computes the total number of parameters in the model.
- **Flexible & Robust:** Can handle any FLAX model architecture, including those with complex hierarchies of nested layers.

## Function: `get_model_config`

### Description

The `get_model_config` function extracts the configuration of a FLAX model, including detailed information about each layer and sub-layer. It processes both top-level layers and nested layers recursively to ensure that no part of the model architecture is missed.

### Input

- **model**: A FLAX model of type `nnx.Module`. This can be any FLAX model, including complex architectures with nested layers.

### Output

- A dictionary containing the following information:
  - **Model Name**: The name of the model class.
  - **Layer Information**: A dictionary with each layer's configuration, including:
    - Layer name
    - Layer type (class name)
    - Input/output dimensions
    - Number of parameters
    - Data type of the parameters
  - **Total Number of Parameters**: The total number of parameters across the entire model.