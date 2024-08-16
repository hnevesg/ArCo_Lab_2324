# Task 3: Vectorization

## Questions

* Before starting the vectorization process, it is crucial to understand the specifics of your machine. What are the SIMD multimedia extensions available on your architecture?

  My core model is 11th Gen Intel Core i5-1135G7 [from advisor and checked by using *lscpu* command], and its instruction set SIMD extensions available [from Intel website] are SSE4.1, SSE4.2, AVX2, and as mentioned before AVX-512.
  
* Review the analysis you've conducted on the complexmul.cpp program. Intel Advisor should have identified an underutilization of instructions, directly related to vectorization, as it indicates that you have available SIMD extensions that are not being leveraged. To vectorize the algorithm, Intel Advisor itself provides guidance on how to proceed. What steps have you taken to vectorize the loop? Keep in mind that you should pursue maximum vectorization that your architecture permits.

  - Regarding **zmm registers** explained in task2: -qopt-zmm-usage.
  - Regarding **compiler optimization** itself: -O2.
  - Regarding the previous **SIMD extensions**: -axCOMMON-AVX512 -xCORE-AVX2.
  - Regarding **OpenMP**, the SIMD directive was included in the code for the 'j' loop: #pragma omp simd.

  Final command used: icpx -g -O2 -qopenmp -axCOMMON-AVX512 -xCORE-AVX2 -qopt-zmm-usage=high complexmul.cpp -o lab3_task3

  The results obtained in Adivsor of my performance were: performance = **50.33 GFLOPS** & Arithmetic Intensity = **1 FLOP/Byte**.
And the peak values: performance = **103.69G FLOPS** & Arithmetic Intensity = **2.49 FLOP/Byte**.

* After vectorizing the program, conduct an analysis and save it under the name "task3":
   * What is the value indicated in the 'Vector Length' field? Considering the extensions you're utilizing and the program's use of 32-bit floats, is this the expected value? Justify the anticipated value, whether the actual value aligns with your expectations or not.
     
     The **vector length** is equal to 512-bit zmm registers / 32-bit floats = **16**.
     
     So the times Advisor uses value 16, it is the expected value. However, when it is 8, it does not take full advantage of my computer's SIMD capabilities.
     
   * What was the extent of the improvement? Discuss whether this is the outcome you predicted; if not, explain what you believe might be the reason (Hint: Intel Advisor can offer insights into what the issue might be).

     It **significantly improved the performance**, but it is not as close to the peak performance values as I expected. Advisor says *"This loop is mostly compute bound but may also be memory bound. The bottleneck depends greatly on the accessed computational unit"*, this means that depending on the operations executed in the loop of lines 27-33, the performance is affected by both, memory and compute bounds.
