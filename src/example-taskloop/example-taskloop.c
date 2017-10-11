#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <pthread.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#define omp_get_num_procs()                             \
  (system("cat /proc/cpuinfo | grep 'processor' | wc -l"))
#endif

void func(){
  int i, j;
  fprintf(stdout, "Thread[%lu,%lu]: taskloop...\n", omp_get_thread_num(), (long int) pthread_self());  
  #pragma omp taskloop num_tasks(8) private(j) grainsize(2)
  for (i = 0; i < 16; i++) {
    for (j = 0; j < i; j++) {
      fprintf(stdout, "Thread[%lu,%lu]: Trabalhando na iteração (%d,%d).\n", omp_get_thread_num(), (long int) pthread_self(),i,j);  
    }
  }
}

int main(int argc, char *argv[]) {

  fprintf(stdout, "Thread[%lu,%lu]: Antes da Região Paralela.\n", (long int) omp_get_thread_num(), (long int) pthread_self());

  #pragma omp parallel num_threads(4)
  {
    #pragma omp single
    {
      fprintf(stdout, "  Thread[%lu,%lu]: Antes das tasks.\n", (long int) omp_get_thread_num(), (long int) pthread_self());
      #pragma omp taskgroup
      {
        #pragma omp task
        {
          fprintf(stdout, "Thread[%lu,%lu]: Trabalhando na task avulsa.\n", omp_get_thread_num(), (long int) pthread_self());
        }
        
        #pragma omp task
        {
          fprintf(stdout, "Thread[%lu,%lu]: Trabalhando na task func().\n", omp_get_thread_num(), (long int) pthread_self());  
          func();
        }
      }
    }
  }

  fprintf(stdout, "Thread[%lu,%lu]: Depois da Região Paralela.\n", (long int) omp_get_thread_num(), (long int) pthread_self());
    
  return 0;
}
