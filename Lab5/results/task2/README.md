
# Task 2
Code in src/task2/buffer.cpp should represent the following flow:
1. Initialize buffer A
2. Add to each item in A the index of the iteration
3. Initialize buffer B the same way than A
4. Compute B as the result of B multiplied by A

## Check the result and show it below
Result:
0
2
8
18
32
50
72
98
128
162
200
242
288
338
392
450

## Which abstraction is being used for data containers?
Buffers are used, and also accessors are being used because buffers cannot be directly accessed. Specifically, they are unidimensional integer arrays: buffer<int> A{R}.

## How is the DAG being built implicitly or explicitly?
Implicitly, there's no "handler.depend_on(variable)".

## Enumerate all dependencies and their types
- WAW & RAW: when A items are added [write] their corresponding indexes [read] after being A initialized. (At kernel 2)
- WAW: when B items are multiplied by A's after being B initialized. (At kernel 4)
- RAW: between B and the new values of A after the indexes addition (kernel 2). (At kernel 4)
