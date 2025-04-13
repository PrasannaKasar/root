import numpy as np
import onnx
from onnx import helper, TensorProto

# Define input dimensions
input_dim_1 = 4
input_dim_2 = 5
output_dim = 6

# Create input tensors for A, B, and C (bias)
A = helper.make_tensor_value_info('A', TensorProto.FLOAT, [input_dim_1, input_dim_2])
B = helper.make_tensor_value_info('B', TensorProto.FLOAT, [input_dim_2, output_dim])
C = helper.make_tensor_value_info('C', TensorProto.FLOAT, [input_dim_1, output_dim])  # Bias

# Create output tensor (the result of the GEMM operation)
output = helper.make_tensor_value_info('output', TensorProto.FLOAT, [input_dim_1, output_dim])

# Create GEMM node
gemm_node = helper.make_node(
    'Gemm',  # Name of the operator
    inputs=['A', 'B', 'C'],  # Inputs for A, B, C
    outputs=['output'],  # Output for the result
    alpha=2.0,  # Scaling factor for A * B
    beta=3.0,   # Scaling factor for C
    transA=0,   # No transpose on A
    transB=0    # No transpose on B
)

# Create a graph that consists of the GEMM node
graph = helper.make_graph(
    [gemm_node],  # The GEMM node is the only operation in the graph
    'GemmModel',   # Model name
    [A, B, C],     # Model inputs
    [output]       # Model outputs
)

# Create the model
model = helper.make_model(graph, producer_name='onnx-example')

# Save the model to a .onnx file
onnx.save(model, 'gemm_model.onnx')

print("ONNX model with GEMM operator saved as 'gemm_model.onnx'")
