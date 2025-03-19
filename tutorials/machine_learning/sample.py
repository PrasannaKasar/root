import onnx
from onnx import helper
from onnx import TensorProto

# Create a graph that contains a single ReLU operator
input_name = 'input'
output_name = 'output'

# Create the input tensor (a 2D tensor with shape [1, 3])
input_tensor = helper.make_tensor_value_info(input_name, TensorProto.FLOAT, [1, 3])

# Create the output tensor (same shape as input)
output_tensor = helper.make_tensor_value_info(output_name, TensorProto.FLOAT, [1, 3])

# Define the ReLU node
relu_node = helper.make_node(
    'Relu',  # The operator is ReLU
    inputs=[input_name],  # Input tensor
    outputs=[output_name],  # Output tensor
)

# Create the graph
graph = helper.make_graph(
    [relu_node],  # The node in the graph (in this case, the ReLU operator)
    'simple_relu_model',  # Name of the model
    [input_tensor],  # Input tensors
    [output_tensor],  # Output tensors
)

# Create the model
model = helper.make_model(graph, producer_name='onnx-example')

# Save the model to a file
onnx.save(model, 'simple_relu_model.onnx')
