#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#define omp_get_num_procs() (system("cat /proc/cpuinfo | grep 'processor' | wc -l"))
#endif

// Size of vectors.
#ifndef N
#define N 8
#endif

int loop_0[N];
int loop_1[N];

int main() {
  int i;
  int loop_index;
  
  #pragma omp parallel num_threads(1)
  {
    loop_index = 0;
    #pragma omp for schedule(dynamic)
    for (i = 0; i < N; i++) {
      // printf("loop: %d, thread: %lu, iteration: %d\n", loop_index, omp_get_thread_num(), i);
      loop_0[i] = omp_get_thread_num();
    }
    
    loop_index = 1;
    #pragma omp for schedule(runtime)
    for (i = 0; i < N; i++) {
      // printf("loop: %d, thread: %lu, iteration: %d\n", loop_index, omp_get_thread_num(), i);
      loop_1[i] = omp_get_thread_num();
    }
  }
  
  printf("Fora da região paralela.\n");
  for (i = 0; i < N; i++) {
    printf("loop_0[%d]: %lu, loop_1[%d]: %lu\n", i, loop_0[i], i, loop_1[i]);
  }
    
  return 0;
}
