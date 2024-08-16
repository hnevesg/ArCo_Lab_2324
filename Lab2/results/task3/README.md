# pi.cpp
## Comparison between original program and changed one to improve parallelization
First of all, Barrier and SIMD were not used. The first one because there's no need for an explicit barrier, since the parallelization ends at the same time that the for loop does; and the second because there is no vector, this code consists in adding a calculation to the sum variable.

### Original code
With the *initial* code, the sequential program lasted 0.0000389170 s. 

The times with the different OpenMP directives, using **4 threads** were [image not available]
Along with the schedule directive, critical is used due to the update of the variables sum and xi.

### Alternative code
For a better parallelization, variables i and xi were made local, as well as overwriting the xi value in each iteration instead of accumulating a value.

With this *new* code, the sequential program lasted 0.0000388630 s.

The times with the different OpenMP directives, using **4 threads** were [image not available]

### Conclusion
The performance of the program using OpenMP is worse compared to the sequential one. As well as in the two other tasks, the nature of the program itself is sequential, and applying parallelism requires extra work to manage and coordinate the threads. In this case, the extra work consumes more time than the benefits gained from parallel exectuion.

One detail is that *atomic* has taken less time than *critical* in all tasks' executions, and this is because only the write operation is done atomically instead of imposing mutual exclusion during the whole section (only one thread can access the resource.)
