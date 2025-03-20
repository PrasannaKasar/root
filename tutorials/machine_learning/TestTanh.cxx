#include <numeric>

#include "Tanh.hxx"
#include "input_models/references/Tanh.ref.hxx"

#include "gtest/gtest.h"

constexpr float DEFAULT_TOLERANCE = 1e-3f;

TEST(ONNX, Tanh)
{
   constexpr float TOLERANCE = DEFAULT_TOLERANCE;

   // Preparing the random input
   std::vector<float> input({
     -0.3896, -0.3521,  0.0363,  1.0962,  0.5085, -0.8523, -0.6766,  0.2421,
      1.5971,  1.3873, -0.2112, -0.6895, -0.5069, -2.1395, -0.7087,  1.1658,
      1.3493,  0.8132,  1.7156, -0.8637, -0.1971,  0.0411, -0.5662, -0.2516
   });

   TMVA_SOFIE_Tanh::Session s("Tanh_FromONNX.dat");

   std::vector<float> output = s.infer(input.data());

   // Checking output size
   EXPECT_EQ(output.size(), sizeof(Tanh_ExpectedOutput::outputs) / sizeof(float));

   float *correct = Tanh_ExpectedOutput::outputs;

   // Checking every output value, one by one
   for (size_t i = 0; i < output.size(); ++i) {
      EXPECT_LE(std::abs(output[i] - correct[i]), TOLERANCE);
   }
}
