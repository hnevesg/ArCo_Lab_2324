# Task 1
In this task, you will parallelize part of the code using DPC. Specifically, you will need to translate the centroid operation to DPC.

## Prepare the code
First, locate the code corresponding to the centroid and how the hyperspectral cube is read from the image hosted on [mega](https://mega.nz/file/Z5JUkSoI#boptGx0TD4YU1FGz5WxVkxgB0-fav1sQiVVCk2lz_CA). Remember that this time we will only use one block, so you need to modify the amount of data to be read.

* The code corresponding to the centroid is the method averagePixel().
* The modification of the number of blocks is done in the Main_Compresor_HW.cpp file, inside the runCompressor method, in line 83: unsigned int nBlocks = 1;

## Create the queue using a default device selector
Find out how to create the queue and pass the default device selector as a parameter to the queue. Remember that the queue has to be created before any computation.

* cl::sycl::default_selector selector;
* cl::sycl::queue q(selector);	

## What is the queue used for?
**Answer here**

* It allows communication between the devices and the host. 
* The definition of queue in this context is: Abstraction of a channel to send executions units to a single device.

## Create the corresponding buffer for each array
Remember that one of the ways to access memory in DPC is through buffers and accessors. This is the method we will use in this practice. To do this, create the buffers once the memory spaces where we will work are initialized, i.e., just before the for loop.

* cl::sycl::buffer <unsigned short, 1> buff_imgRf{ImgRef, cl::sycl::range<1>(BANDS*BLOCK_SIZE)};
* cl::sycl::buffer <int, 1> buff_centrd{centroid, cl::sycl::range<1>(BANDS)};

## Create a range for the kernel
The first parameter of the *parallel_for* will be the workspace range. To define this range, we have to indicate, at compile time, the number of dimensions it has and the size of each dimension.
* Since ImgRef and centroid are unidimensional arays, the range will have 1 dimension, and the size will correspond to the condition in the for loop.

## Submit a task to the queue
Now we will create the job inside the queue where, in the following tasks, we will insert the code to: request access to variables and execute the job. Find out how to create the job for the queue. Verify that the code compiles.
* q.submit([&] (cl::sycl::handler& h)

## Request access to buffers
Remember that we have created buffers to abstract access to different variables. As seen in theory, you have to request access to each buffer through accessors. **In the first lines within the queue**, define the accessors that we need.

Clues: Choose the right permissions.

* cl::sycl::accessor accessorImg{buff_imgRf, h, cl::sycl::read_only};
* cl::sycl::accessor accessorCentroid{buff_centrd, h, cl::sycl::read_write};

## Create the parallel_for
Now that we have access to each buffer, we need to request, through the handler, the parallel_for indicating: the kernel's range (review the previous steps) and the kernel itself. Initially, leave the kernel empty and check that the compilation is correct.

Once the parallel_for is completed (remember to add the centroid calculation code in the kernel), compile the code and make sure there are no compilation errors.

Clues: Look in the reference code. Most likely, you will need to adapt the reference code to the structure followed by DPC.

* h.parallel_for(cl::sycl::range<1>(BANDS), [=](auto& idx)

## Wait for the task and get the results
Finally, all that's left is to wait for the queue. Find out how to wait and access the kernel's output buffer using a host_accessor. By creating the host_accessor to the buffer, the runtime ensures that you have access to it, and you can access it as you normally would.
* After the closing bracket of the q.submit , q.wait(); is added.
* Then, the host accessor is created: 

   cl::sycl::host_accessor accCentroid(buff_centrd, cl::sycl::read_only);\
  	  for (int i = 0; i < BANDS; ++i){\
    	  std::cout << accCentroid[i] << "\n";\
       }\
    std::cout << "\n";

**Verify that the code produces the same results as the sequential code**

* The result for block 0 is the same as the sequential one: [b0.txt](results/task1/b0.txt)

**Save the final code in results/task1/dpcHLCA.cpp**

* The file with DPC modifications: [dpcHLCA.cpp](results/task1/dpcHLCA.cpp)
