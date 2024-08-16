# Comparison and analysis of the results
## Time
My pc took **23s** (CPU Time) to finish the computations, while the devcloud environment took just **11s** for the same task . This is probably thanks to the many logical CPUs that enable multiple threads. 
## Performance
The same program was executed in both of them and in my pc lasted more, and taking into account that **devcloud** can parallelize more, it has a **better performance**.

Concerning the frequency, that is how many cycles a CPU can execute in a given time, in the devcloud environment is *3.4GHz* and in my pc is *2.4GHz*. Therefore, the **devcloud environment executes more instructions per second**.

However, in the devcloud environment the performance depends on the load of the users, although in our case each user is allocated their own nodes.
## Memory measures
In the analysis of both of them a 56% of the memory is used, so *memory constraints* were *not a significant factor* influencing the performance difference observed.
