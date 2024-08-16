
# Task 2
One the parallelization task is completed you'll check the performance of the solution.

## Create a table for each image and configuration (serial, parallel) with the average times for each combination, you must use several blocks
**Answer here** **Explain the results obtained***

With the averagePixel method parallelized with dpc/sycl, it is faster than the sequential program. However, with more methods parallelized there is overhead and it takes more time.

Being n = (COLUMNS*LINES) / BLOCK_SIZE;

| Configuration                                   | Time       |
|--------------------------------------------------|------------|
| **For n blocks and averagePixel parallelized:**  |            |
| Sequential                                       | 15.47s     |
| Parallel (DPC)                                   | 13.70s      |
|                                                  |            |
| **For n blocks and averagePixel and quVectors parallelized:** |            |
| Parallel (DPC)                                   | 153.16s    |
|                                                  |            |
| **For n blocks and averagePixel, quVectors, and duplicateAndCentralizeImg parallelized:** |            |
| Parallel (DPC)                                   | 167.13s    |
|                                                  |            |

## Modify the code to deploy it in a GPU, using devcloud for the testing

[dpcHLCA_gpu.cpp](results/task2/dpcHLCA_gpu.cpp)
## Modify the previous table to include the timing with respect to the GPU
**Answer here**

| Configuration                                   | Time       |
|-------------------------------------------------|------------|
|                                                  |            |
| **For n blocks and averagePixel parallelized:**  |            |
| Sequential                                       | 15.47s     |
| Parallel (DPC with **GPU**)                                   | 11.22s     |
|                                                  |            |
| **For n blocks and averagePixel and quVectors parallelized:** |            |
| Parallel (DPC with **GPU**)                                    | 9.71s      |
|                                                  |            |
| **For n blocks and averagePixel, quVectors, and duplicateAndCentralizeImg parallelized:** |            |
| Parallel (DPC with **GPU**)                                   | 41.79s     |


The code parallelized with a queue using a GPU instead of a CPU is indeed faster. Apart from the fact that gpus better fit for pixel processing, they have (or at least in this case) more cores, leading to more parallelization.
## How did you run the code in the GPU?
**Write down the devcloud command**

ssh devcloud

qsub -I -l nodes=1:gpu:ppn=2

advisor --collect=roofline --profile-gpu --project-dir=./advi_results -- ./HyperLCA

## Modify the program to gather information about the node running the task in the queue
**Save the resulting code in results/task2/task2.cpp**

The cpu from devcloud:
- Device: 11th Gen Intel(R) Core(TM) i9-11900KB @ 3.30GHz
- Device maximum nº of parallel compute units: 16

The gpu from devcloud: 
- Device: Intel(R) UHD Graphics
- Device maximum nº of parallel compute units: 32