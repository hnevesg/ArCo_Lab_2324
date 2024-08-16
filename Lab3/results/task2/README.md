
# Task2: Roofline
1. Generate a roofline and analyze the information depicted. Copy a screenshot of the roofline in your response to support your analysis. Finally, create a snapshot with the name "task2" and add it to this same folder.
   The **current performance** of the computer is **far away** from the **peak performance**. As the results show:
   the roofline result for performance is 0.61 GFLOPS and for the arithmetic intensity is 0.044 FLOP/Byte, while the peak values are 47.4 GFLOPS & 6.22 FLOP/Byte.

   In the recommendations, it explicitly says *"This loop is mostly memory bound. The performance of the loop is bounded by the private cache bandwidth. The bandwidth of the shared cache and DRAM may degrade perfomance"*. Which means that the **limitations on performance are due to memory access** rather than computational processing.
   
   Also, *"The loop's execution is not making optimal use of the private cache, which can lead to performance limitations 
Bandwidth of Shared Cache and DRAM May Degrade Performance"*. This indicates that the performance is affected because the **shared cache (L3) and the DRAM are very slow** since their capacity is much bigger than for instance caches L1 and L2.

3. Why is the algorithm limited? What techniques could we apply to improve performance?

    Advisor recommends recompiling with **zmm registers** enabled. These are 512-bit registers of the X86 intel arquitecture used for Advanced Vector Extensions (and so, for SIMD I assume).

In addition, it suggests converting the loop to a **vectorized version**, allowing the loop to perform many **operations in parallel**. 
Another option is using compiler optimization (-02).
