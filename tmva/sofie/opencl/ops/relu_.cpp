#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include <vector>

#define VECTOR_SIZE 100000000

int main()
{
    // size_t size = 100000000;

    float* A = new float[VECTOR_SIZE];
    float* C = new float[VECTOR_SIZE];

    // Fill the array with some values (e.g., random values)
    for (size_t i = 0; i < VECTOR_SIZE; ++i) {
        A[i] = static_cast<float>(i % 100);  // Just an example
    } 

   auto start = std::chrono::high_resolution_clock::now();

   for (int i = 0; i < VECTOR_SIZE; i++) {
    C[i] = fmax(0, A[i]);
   }

   auto stop = std::chrono::high_resolution_clock::now();

   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
   double time = duration.count() / 1000.0;

   printf("CPU Execution Time: %.3f milliseconds\n", time);

   // // Print the first 10 results

   for (int i = 0; i < 10; i++) {
      printf("C[%d] = %f\n", i, C[i]);
   }

   return 0;
}