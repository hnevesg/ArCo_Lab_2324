#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>  

int main() {
	auto start_time = std::chrono::high_resolution_clock::now();
	omp_set_num_threads(4);
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
	int max = 0;
	int min = 50;

	#pragma omp parallel for schedule(static,2)
	for(int i = 0; i < 100; i++){
		if (arr[i] < min){
			#pragma omp atomic write
			 min = arr[i];
			
		}else if (arr[i] > max){
			#pragma omp atomic write
			 max = arr[i];
		}
	}

	printf("The result is max: %d, min: %d\n", max, min);
	
	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

	std::cout << "Execution time: " << duration.count() << " nanoseconds" << std::endl;
	
	return 0;
}

