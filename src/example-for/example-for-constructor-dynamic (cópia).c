/* Compile:
 * gcc -fopenmp example-parallel-num_threads.c -o
 * example-parallel-num_threads.exe
 * or
 * make omp-parallel-num_threads
 */
#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#define omp_get_num_procs()                             \
  (system("cat /proc/cpuinfo | grep 'processor' | wc -l"))
#endif

int main() {
  int id, i;

  printf("Thread[%d][%lu]: Antes da Região Paralela.\n", omp_get_thread_num(), (long int) pthread_self());

  #pragma omp parallel num_threads(4) default(none) private(id)
  {
    // All threads executes this code.
    id = omp_get_thread_num();

    #pragma omp for schedule(static,2)
    for(i=0; i<16; i++){
      printf("Thread[%d][%lu]: Trabalhando na iteração %lu.\n", id, (long int) pthread_self(), i);
    }
  }
  
  printf("Thread[%d][%lu]: Depois da Região Paralela.\n", omp_get_thread_num(), (long int) pthread_self());

  return 0;
}
