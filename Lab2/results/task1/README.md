# Program that identifies the maximum and minimum values within a vector's components
## Comparison
### With 5 elements in the vector
(I used the chrono primitive because the time primitive was not accurate enough)

With *5 elements* in the vector, the sequential program lasted 38710 ns.

The times with the different OpenMP directives, using **4 threads** were bigger.

Also, with the *schedule directive* it took a *lot of time*.<br><br>

Barrier and SIMD were not used. The first one because there's no need for an explicit barrier, since the parallel region ends immediately after the loop; and the second because that kind of parallelism is only suitable when the same operation can be applied in parallel to multiple data elements (and not in conditionals).
### With 100 elements in the vector
While, with *100 elements in the vector*, the sequential program lasted 48611 ns.

The times with the different directives with **4 threads** were much bigger.

And the same for the schedule directive.<br> <br>

I also tried with a very **high number of threads** and it took even **more time**.

### Conclusion
The performance of the program using OpenMP directives is worse than the sequential way. I believe that this is due to the nature of the program itself, meaning that **this program doesn't have enough parallelism** to use the available cores, resulting in extra work for managing threads.
