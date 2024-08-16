# Task 1: Intel Advisor

This tasks requires the compilation and executio of the HyperLCA code. You have a makefile that automates those operations.
Type **make** to compile the code and **make run** for the execution.
Take into account that you should first download a data file from 'https://mega.nz/file/Z5JUkSoI#boptGx0TD4YU1FGz5WxVkxgB0-fav1sQiVVCk2lz_CA'

**In this exercise you CAN'T user -xCORE-AVX2 optimization since you are expected to manually specificy vectorization through manually edited pragmas**
# Task 1: Intel Advisor

## Questions
* Before beginning any analysis, it's important to understand your architecture's characteristics. Please answer the following questions:
    * State your processor model and the number of cores it has.
      <br>My processor model is 11th Gen Intel Core i5-1135G7 [from advisor and checked by using lscpu command], and its number of **cores is 4**.
    * How many threads can be executed per core?
      <br>Every core can execute **2 threads**.
      
* Next, proceed to introduce annotations in all the loops that should be parallelized (at least, specify three sites for analysis). These annotations will allow the analysis program to consider these loops for parallelization and make the appropriate estimates. Save the modified program with annotations using the suffix "_annotated" (keep in mind that in addition to including annotations, you must include/modify a new header file).
  <br> The header file included is **advisor-annotate.h**.

* Specify the command you would use to compile the program with the annotations (Tips: Look for the -I option and locate the path to the advisor-annotate.h file within the intel/oneapi directory).
  <br> Command used to compile with the annotations: **-I/opt/intel/oneapi/advisor/2023.2.0/include**.
