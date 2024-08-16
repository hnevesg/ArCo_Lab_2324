
# Task 4
Code in src/task4.usm.cpp tries to compute the addition of a series of values over each item of an arrray. After the 
computation the result must be 20 for each item. The code may seem correct, and even provide a correct result when run.
However, that doesn't mean that it's correct. That is not strange in parallel programs.

Here the problem is that all kernels can access shared memory concurrently. If you pay attention you'll see no explicit
data dependence in the code, which may cause that two taks access in an incoherent way: one item of data read can be modified
after the reading, thus the task could update the new value with a wrong partial result.

This problem can be solved in different ways:
1. Set dependencies using events
2. Set dependencies using waits
3. Set dependencies using in_order_queues

## Modify the code to solve race conditions using events
[usm_events.cpp](src/usm_events.cpp)
## Modify the code to solve race conditions using waits**Store the code in results/task4/src/usm_waits.cpp**
[usm_waits.cpp](src/usm_waits.cpp)
## Modify the code to solve race conditions using an in_order_queue
[usm_inorder.cpp](src/usm_inorder.cpp)
