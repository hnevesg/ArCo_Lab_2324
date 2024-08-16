# Task 4: Memory Analysis and Vectorization improvement

## Questions:

* Recompile the complexmul.cpp program without vectorization and generate a memory analysis, highlighting the computation loops that perform the multiplication of complex numbers. Specifically, mark the loops on lines 27 and 28 (if the analysis takes too long, consider reducing the size). Conduct the analysis using both the Intel Advisor graphical interface and the command line. Also, specify the command you used for the command-line analysis.
  
  I reduced the size from 50000 to 5000 to make it faster (only for this case, that is not vectorized). Both loops have constant and variable strides.
  
	*Commands used*:
      icpx -g -qopenmp complexmul.cpp -o lab3_task4 <br>
      	advisor -collect map -mark-up-list=16,17 -project-dir /home/intel/advixe/projects/lab3_task4 --app-working-dir=/home/Downloads -- /home/Downloads/lab3_task4_5000
	

* Open Advisor and select the "Refinement Reports" view.

  * What information does this view provide? List each item in the table, summarizing its meaning.
    - **Site location**: the line of code in which the loop (in this case) is located.
	 - **Loop-carried dependencies**: the corresponding dependency (WAW;RAW;WAR).
	 - **Strides distribution**: the ratio of stride types for a selected function. It is color-coded:
       - *Blue* is unite stride, which means that the instructions access memory sequentially or within the distance of one element.
       - *Yellow* is constant stride, which means that the instructions access memory with a constant step of more than one element.
       - *Red* is irregular stride, which means that the instructions access memory addresses that change by an unpredictable number of elements from iteration to iteration.
	 - **Access patterns**: information about the stride types.
	 - **Footprint estimate**: the memory footprint estimate for the selected loop.(3 parts: maximum per-instruction address range, first instance site footprint, simulated memory footprint)
	 - **Site name**: sequence ID for the selected loop to be deepen analyzed.
        
  * What memory behavior is observed? Why is it desirable to have a uniform stride?
    <br>It is observed a *constant* (stride 2) and unite *strides behaviour*, which means that *data is not contiguous in memory*.
    <br>Since **uniform stride** means that the access to RAM takes the *same amount of time* for any memory address for all processors, it provides **low latency**, ensuring fast (and efficient) memory access.
    <br>This is suitable for high performance computing applications.
  * Examine the memory analysis results for both loops and confirm that the stride is 2.

  * Why is the stride value set at this level? (Review the concepts of row-order and column-order, as well as the order in which memory is allocated in C).
    <br>Because a number is composed of a real and an imaginary part, and in the nested loops both parts are calculated at every iteration.
    
  * Which variables are being accessed with a stride of 2? How does this affect the cache?
    <br>The variables (arrays) that are accessed with stride 2 are a & b.
    It affects the cache because useful data is deleted, leading to cache misses and having to reload the data into the cache.

  * Can you think of a way to modify the program, keeping the two loops and the same outcome, so that variable access is uniform? Implement the change and save the result in this same folder with the name complexmul_unit_stride.cpp.
<br>Maybe a way is creating separate arrays, 3 with real numbers and another 3 with imaginary numbers that access contiguously in memory.
    
* Generate a snapshot for the complete analysis (up to memory access patterns) for both the version with a stride of 2 and the version with a unitary stride (both vectorizing the code). Name them "task4a" and "task4b", respectively, and add them to this same folder.
  * In "task4b," what are the values for vector length and the estimated gain? Are these the expected results? Justify your answer.
     <br>I obtained the same value for the vector length (16) as the used extensions were the same,and the estimated gain field appears empty,

  * Comparing these two solutions, by how much has the gain increased?
* Compare the analysis results of task2 and task4b:
  * What was the actual gain from the vectorized algorithm? Was it less or more than the estimate?
    <br>[I cannot see the gain neither the estimated gain.]
    <br>There's an important gain because unti strides maximize cache line utilization, as it is accessed data that is stored close together in memory, meaning multiple data elements can be loaded into the cache within the same cache line; This maximizes the utilization of cache lines.
    <br> And there's a very big difference with respect to task 2: