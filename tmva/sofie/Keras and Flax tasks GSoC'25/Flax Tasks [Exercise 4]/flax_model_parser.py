from pprint import pprint

def get_model_config(model: nnx.Module) -> dict:
    '''
    Extracts the configuration of a Flax model recursively, so that any nested layers are not missed.

    Input:
        model: Flax model of type nnx.Module

    Output:
        A dictionary containing the model configuration, including:
        - Model name
        - Layer information (name, type, input/output dimensions, number of parameters, data type)
        - Total number of parameters in the model
    '''
    # Initialize a dictionary to store the overall model configuration
    model_config = {}

    # Store the model's class name (i.e., model type)
    model_config['Model Name'] = model.__class__.__name__

    # Initialize a dictionary to store detailed layer-wise information
    model_config['layer information'] = {}

    # Initialize a list to store the number of parameters used in every layer
    layer_param_counts = []

    # Helper function to recursively gather configuration data from the layers of the model
    def helper(layer_dict, layer_obj):
        '''
        Recursive function to extract configuration for each layer and its parameters
        
        Input:
            layer_dict: Dictionary to store layer information (will be passed recursively)
            layer_obj: The current layer object to extract information from
        '''

        # Iterate over the children (layers) of the current layer object
        for layer_name, layer_params in layer_obj.iter_children():

            # Initialize a new dictionary entry for each layer in the main dictionary
            layer_dict[layer_name] = {}

            # Store the class name of the current layer
            layer_dict[layer_name]['class'] = layer_params.__class__.__name__

            # If the current layer has nested layers, recursively extract information from those
            if any(layer_params.iter_children()):
                # If nested, initialize a dictionary for the nested layers
                layer_dict[layer_name]['layers'] = {}
                # Recursively call helper for nested layers
                helper(layer_dict[layer_name]['layers'], layer_params)
            else:
                # For layers without further nested layers, iterate over the parameters of the layer
                for param_type, param in vars(layer_params).items():

                    # Consider only parameters of type 'Param' with a 2D shape (weights/kernels)
                    if param.__class__.__name__ == 'Param' and param.value.ndim == 2:
                        # Extract the shape of the parameter (input_dim, output_dim)
                        param_shape = param.value.shape

                        # Store the input/output shape of the layer
                        layer_dict[layer_name]['shape'] = {
                            'input shape': (None, param_shape[0]),
                            'output shape': (None, param_shape[1])
                        }

                        # Calculate the total number of parameters for this layer
                        # Formula: (input_dim * output_dim) + output_dim (for the bias)
                        layer_param_count = param_shape[0] * param_shape[1] + param_shape[1]

                        # Append the number of parameters of this layer to the list
                        layer_param_counts.append(layer_param_count)

                        layer_dict[layer_name]['number of parameters'] = layer_param_count

                        # Store the data type of the parameters in the layer
                        layer_dict[layer_name]['dtype'] = str(param.value.dtype)

    # Start the recursion by passing the model's base layer information dictionary and model object
    helper(model_config['layer information'], model)
    # Calculate the total number of parameters used in the model
    total_number_of_params = sum(layer_param_counts)
    # Store the total number of parameters in the model configuration
    model_config['Total number of parameters'] = total_number_of_params
    # Return the final model configuration
    return model_config

# Print the model configuration
model_config = get_model_config(model)

pprint(model_config)
