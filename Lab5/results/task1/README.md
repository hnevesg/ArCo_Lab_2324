
# Task 1
Get familiar with Intel DPC compiler.
First copy the code in src/task1/query.cpp to results/task1/src and compile it with dpcpp.

## Which output do you obtain?
The name of my device, "Device: 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz".ç
<br>And the command I used: icpx -fsycl query.cpp. <br>

## Which different types of selectors do we have in DPC? Can we obtain a GPU? What happens if the requested device doesn't exist?
Devices: CPU, GPU (so yes to the second question), TPU and FPGA...
<br>In case the device is not available "No device of requested type available. Aborted (core dumped)".

It is very likely that some of the devices that can be used with DPC are not available in your PC. Don't worry about that, since we can use devcloud for such purpose.

## Try to obtain a GPU from devcloud by the query.cpp program into gpu_query.cpp
[gpu_query.cpp](src/gpu_query.cpp)

## How did you obtained the GPU? How have you requested qsub that you want a node with a GPU?
Yes, with the command *qsub -I -l nodes=1:gpu:ppn=2. Nodes=1 means 1 node requested, ppn=2 means two processors per node, and gpu means one GPU per node.

The output is "Device: Intel(R) UHD Graphics"

## Modify the program to obtain more data from the device.
[more_query.cpp](src/more_query.cpp)
<br>Now, the vendor, version, maximum nº of parallel compute units, and maximum work group size used to execute a kernel are also obtained.
