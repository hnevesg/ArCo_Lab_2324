# sumavector.cpp
## Comparison with 50 & 5000 elements in the vector
(I used the chrono primitive because the time primitive was not accurate enough)

With *50 elements* in the vector, the sequential program lasted 82613 ns. While, with *5000 elements in the vector*, the sequential program lasted 4108810 ns.

The times with the different OpenMP directives, using **4 threads** were big.

Barrier and SIMD were not used. The first one because there's no need for an explicit barrier, since they are used to ensure that all threads have reached a specific point in the code before proceeding (we don't need this); and the second because it is sum += v[i] and not for instance w[i] = i + v[i] which would be independent.

In addition, I want to point out that this directive is not used in the third loop because it probably would print the values in an unordered way.

Again, I tried with *lots of threads* and it took even *more time*.

### Conclusion
The performance of the program using OpenMP directives is worse than the sequential way. Just like in task 1, the nature of the program itself is sequential, and applying parallelism results in additional work for managing threads.


Finally, the variable i is unnecessarily shared.
