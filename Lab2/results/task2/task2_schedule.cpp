/* Programa secuencial que calcula la suma de los elementos de un vector v[i] 
 * y la almacena en la variable sum */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <chrono>
#include <iostream> 
#include <omp.h>
#define N 5000 // Probar distintos tamaños de vector 

int main() 
{ 
	auto start_time = std::chrono::high_resolution_clock::now();
    int i, sum = 0; 
    int v[N];    
	omp_set_num_threads(4);
	
    // Damos valores aleatorios al vector (entre 0 y 99) 
    srand (time(NULL)); // Semilla de números aleatorios 
    #pragma omp parallel for schedule(static,5)
    for (i = 0; i < N; i++) v[i] = rand()%100; 

    // Cálculo del sumatorio 
    #pragma omp parallel for schedule(static,5)
    for (i = 0; i < N; i++){
     #pragma omp atomic
     sum += v[i];           
    }

    // Como comprobación, se visualizan los valores del vector y la suma 
    printf("\nVector de números: \n "); 
    #pragma omp parallel for
    for (i = 0; i < N; i++) printf("%d \t",v[i]);
    
	printf("\n La suma es: %d \n\n", sum); 
	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

	std::cout << "Execution time: " << duration.count() << " nanoseconds" << std::endl;
	
	return 0;
} 
