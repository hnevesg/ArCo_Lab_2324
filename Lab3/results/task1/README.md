
# Task 1: Intel Advisor

## Questions
* Within the "Survey & Roofline" view, references are made to both Total time and Self-time. What is the difference between these two terms?
  
   Total time: Time actively executing a function or loop and its callees (all threads).
  
   Self-time: Time actively executing a function or loop, not including time for functions called in the loop or function.
* Conduct a Survey analysis, navigate to the "Survey & Roofline" tab, and capture the information displayed (this will be used later).

  
* Click on the roofline within the "Survey & Roofline" and observe that no chart appears. What could be the reason for this absence?

  No chart is shown because Flop Count is not activated, and the roofline consists in doing a plot with the X axis as Arithmetic Intensity (measured in FLOPs/Byte) and the Y axis as the performance in GFLOPs/Second. So it does not have enough information to do it.
  
* Perform an analysis focusing on trip-counts and FLOP (Floating Point Operations). What new information is presented in the survey view? Capture this information and discuss the most pertinent new data.

   The most relevant new data, that give more information regarding performance, are:
  - Memory bandwith: it is a measure of how quickly data can be read from or written to memory. In advisor is expressed in GB/s and represents the rate at which data can be transferred between the CPU and memory.
  - Peak performace: it is the upper bound of the plot. Or in other words, how much the performance can improve. It is measured in FLOPS (Floating Point Operations).
  - Arithmetic intensity: it measures the computational work relative to data transfer. It can sound very similar to the memory bandwith, but this measures how efficiently the data is used for computations. It is measured in FLOP/byte (computations per data transfer).

  The roofline also graphically shows the performace roof, making it easier to understand.