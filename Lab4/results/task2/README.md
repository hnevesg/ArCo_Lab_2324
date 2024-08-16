
# Task 2: Threading Analysis
## Questions

* Proceed with the threading analysis up to the **Suitability** analysis.

* Before interpreting the results, it is important to understand the represented information. Go to the Suitability Report tab and answer the following questions:
    * What does the Scalability of Maximum Site Gain graph represent? What are the purposes of the Avg. Number of Iterations and Avg. Iteration Duration options?

       It represents how much gain we can obtain if we add parallelism, based on the number of cores we use. The red point that looks like a target is our current gain using 'x' cores.
      <br>Regarding the 2 options, the number of iterations and the instance durations, they can be changed, allowing to make *predictions of the time performance with parallelization*.
      
    * Explain the meaning of each field in the columns **Impact to Program Gain**, **Combined Site Metrics, All Instances** & **Site Instance Metrics, Parallel Time**
     	<br>
      - **Impact to Program Gain**: estimated gain thanks to applying parallelization
      - **Combined Site Metrics, All Instances**: the time spent in the sequential operations and the parallel ones.
      - **Site Instance Metrics, Parallel Time**: total execution time for the specific code region

* Analyze the scalability of gain for each of the Sites you've defined:
    * First, configure the report according to your system and the threading model you plan to use.

         My system: *4 cores and 2 threads* per core. Threading model: OpenMP. <br>
    * Take a snapshot and save it with the name task2 in the [task2](/results/task2) folder.

        The snapshot weighted more than 25MB, so here's a capture: [Task 2 capture](/results/task2/task2.png)
      
    * For each of the defined Sites, specify from how many CPUs the gain ceases to improve or even worsens, and justify why this occurs.
      <br> The 1st loop (HyperLCA_transform method) has the same behaviour independently of the nº of cores used.
      <br> The 2nd loop (lines 92-101, averagePixel method) can be efficiently parallelized. As you *increase the number of CPUs*, the *performance gain* continues to *improve* because the workload can be distributed among the CPU cores.
       <br> The 3rd loop (lines 167-188, projectingImg method) at **16 cores**, the performance worsens **due to the overhead**.
       <br> And in the 4th loop (lines 192-204, subtractingInformation method) happens the same as in the second one.  
      
    * Which of the loops defined in the code consumes the most execution time in the program? How would reducing the block size from 1024 to 256, using the maximum number of CPUs in the simulation (64), affect the gain of this Site? Explain how you obtained this new gain.
    <br> The most time consuming loop is the one from the HyperLCA_transform method, as it calls lots of functions inside it.
<br> Maybe the second one is the duplicateAndCentralizeImg method because although the brightness and averagePixel methods have the same two nested loops, in the latter ones the reduction directive can be used to apply parallelism.<br>
	<br>After changing the BLOCK_SIZE in Configurations.h to 256, execute the make, and opening it in Advisor: The second loop improves its performance when more cores are used. While the other two **worsen their performance**; maybe the reason could be that **smaller blocks reduce the effectiveness of parallelization**, or the memory access patterns are changed, affecting the efficiency of memory usage. The total gain es 1.67.
