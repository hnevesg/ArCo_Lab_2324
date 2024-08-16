# Task 3: Parallelization with OpenMP

## Questions
* After performing the relevant analyses, parallelize the program to the greatest extent possible, and you can even modify parts of the original code provided for this practice. Keep in mind that you may need to use memory modifiers or synchronization mechanisms.
[Main Compresor HW with parallelization](/results/task3/Main_Compresor_HW_Parallelized.cpp)
[HyperLCA Transform Operations with parallelization](/results/task3/HyperLCA_Transform_Operations.cpp)
[Makefile](/results/task3/Makefile)

* How many threads are available, and what do you think is the reason for this result?
  <br> Using omp_get_max_threads() I obtained **8 threads** as result. I believe this value depends on the hardware capabilities of each computer, since mine has 4 cores and 2 threads per core, then it is 8.
  
* Ensure that both parallel and sequential execution produce the same results. How did you verify this?
  	<br>By checking the *output txt generated* at every compilation.
  
* Perform time measurements for 2, 4, 8, 16, 32, and 64 threads and add the time results to a table alongside the sequential results. Additionally, include the gain achieved for each execution compared to the sequential one. Do these results correspond to or resemble those estimated by Intel Advisor? Justify your answer.

  | Thread Count | Sequential              | Parallel Execution (Time) | Estimated Gain | Real Gain |
  |--------------|-------------------------|---------------------------|----------------|-----------|
  | 1            | 22.348s                 | (No parallelism)          |  -             |  -        |
  | 2            | 33.569s                 | 29.273s                   | 1.06           | 1.15      |
  | 4            | 42.123s                 | 35.842s                   | 1.24           | 1.12      |
  | 8            | 296.920s                | 268.136s                  | 1.12           | 1.11      |
  | 16           | 1438.091s               | 1358.436s                 | 1.12           | 1.06      |
  | 32           | 3176.178                | 3102.820s                 | 1.12           | 1.00      |
  | 64           | 17534.051s              | 17402.436                 |  1.11          | 1.01      |
 
    At 16 cores onwards there's no gain (it is almost the opposite). This could be because an **excessive number of threads** can lead to thread starvation (threads spend more time waiting for resources than performing work).

  It can be seen that the *predictions were not accurate*, probably because it was *not taking into accout the hardware* factors that affect *parallelization performance* (such as OpenMP directives).
