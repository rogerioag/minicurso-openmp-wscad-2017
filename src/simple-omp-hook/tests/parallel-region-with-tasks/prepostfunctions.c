#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

int num_parallel_regions = 0;

int num_loop_dynamic_start = 0;

int num_loop_dynamic_next = 0;

int num_tasks_started = 0;

int num_tasks_finished = 0;

void print_results(){
	printf("Number of parallel regions: %d\n", num_parallel_regions);
	printf("Number of loops with schedule(dynamic): %d\n", num_loop_dynamic_start);
	printf("Number of loop dynamic next: %d\n", num_loop_dynamic_next);
	printf("Number of tasks: %d\n", num_tasks_started);
	printf("Number of Finished tasks: %d\n", num_tasks_finished);
}

void PRE_GOMP_parallel_start (void){
	PRINT_FUNC_NAME;
	num_parallel_regions++;
}

void PRE_GOMP_parallel_end (void){
	PRINT_FUNC_NAME;
}

void POST_GOMP_parallel_start (void){
	PRINT_FUNC_NAME;
}

void POST_GOMP_parallel_end (void){
	PRINT_FUNC_NAME;
	
	print_results();
}

void PRE_GOMP_loop_dynamic_start(){
	PRINT_FUNC_NAME;
	num_loop_dynamic_start++;
}

void POST_GOMP_loop_dynamic_start(){
	PRINT_FUNC_NAME;
}

void PRE_GOMP_loop_dynamic_next(){
	PRINT_FUNC_NAME;
	num_loop_dynamic_next++;
}

void POST_GOMP_loop_dynamic_next(long istart, long iend){
	PRINT_FUNC_NAME;
	printf("%d, %d\n", istart, iend);
}

void PRE_GOMP_task(){
	PRINT_FUNC_NAME;
	num_tasks_started++;
}

void POST_GOMP_task(){
	PRINT_FUNC_NAME;
	num_tasks_finished++;	
}