### Características de los sistemas sobre los que se ejecutan los análisis 
## Procesador
My pc: 11th Gen Intel(R) Core(TM) i5-1135G7 

Devcloud environment: Intel(R) Xeon(R) Gold 6128 

The second one is **designed for servers**, which means that they are  **optimized** for tasks requiring **higher performance** and reliabililty. So this explains why it takes less time to finish the task
Also the pc's one i5-1135G7 has *4 cores* while the other one has *12 cores* which leads to *higher parallelism*.
## Memoria
In the images we see that the percentage of memory used is the same.

![memory_devcloud](https://github.com/ASIGNATURA-ARCO-UCLM/lab1-helenaneves/assets/114600817/cccf1dd8-c893-4f1a-995f-bec29bbba156)
![memory_pc](https://github.com/ASIGNATURA-ARCO-UCLM/lab1-helenaneves/assets/114600817/bfe4c1e9-0402-43df-8c55-e5a335f231fb)


## Caché
Regarding L3 (largest), the Intel Xeon Glod 6128 has a significant L3 cache of 19.25 MB, whereas the Intel Core i5-1135G7 has an L3 cache of 8 MB.
The benefits of having a bigger L3 are, for multi-core applications, that as data sharing is common, it can accommodate a greater volume of shared data, which reduces the need to access data from the RAM (which is slower).
However, the bigger the cache is, the more transistors it has and consequently the more power it consumes.
