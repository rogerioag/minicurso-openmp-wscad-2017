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

int main(int argc, char *argv[]) {

  if(argc < 2) {
      fprintf(stderr, "Uso: %s <x>\n", argv[0]);
      exit(0);
    }

  int id = 0;
  int x = atoi(argv[1]);

  fprintf(stdout, "Thread[%lu,%lu]: Antes da região paralela.\n", omp_get_thread_num(), (long int) pthread_self());

  #pragma omp parallel num_threads(4) firstprivate(x) private(id)
  {
    id = omp_get_thread_num();
    fprintf(stdout, "  Thread[%lu,%lu]: Todas as threads executam.\n", id, (long int) pthread_self());

    #pragma omp single
    {
      fprintf(stdout, "  Thread[%lu,%lu]: Antes de criar tasks.\n", id, (long int) pthread_self());
    #pragma omp task if(x > 10)
      {
         fprintf(stdout, "    Thread[%lu,%lu]: Trabalhando na task 1.\n", omp_get_thread_num(), (long int) pthread_self());
      }
              
      #pragma omp task if(x > 20)
      {
        fprintf(stdout, "    Thread[%lu,%lu]: Trabalhando na task 2.\n", omp_get_thread_num(), (long int) pthread_self());  
      }

      fprintf(stdout, "    Thread[%lu,%lu]: Antes do taskwait.\n", id, (long int) pthread_self());
      #pragma omp taskwait
      fprintf(stdout, "    Thread[%lu,%lu]: Depois do taskwait.\n", id, (long int) pthread_self());

      #pragma omp task
      {
        fprintf(stdout, "    Thread[%lu,%lu]: Trabalhando na task 3.\n", omp_get_thread_num(), (long int) pthread_self());  
      }
    }
  }

  fprintf(stdout, "Thread[%lu,%lu]: Depois da região paralela.\n", omp_get_thread_num(), (long int) pthread_self());
      
  return 0;
}
