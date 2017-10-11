/* Compile:
 * gcc -fopenmp example-parallel-if-false.c -o example-parallel-if-false.exe
 * or 
 * make omp-parallel-if
 */
#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#define omp_get_num_procs() (system("cat /proc/cpuinfo | grep 'processor' | wc -l"))
#endif

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int id;
  int valor = 0;

  printf("Thread[%d][%lu]: Antes da Região Paralela.\n", omp_get_thread_num(), (long int) pthread_self());

  #pragma omp parallel if(n>1024) num_threads(4) default(none) shared(valor) private(id)
  {
    id = omp_get_thread_num();
    long int id_sys = (long int) pthread_self();
    printf("Thread[%d][%lu]: Código Executado por todas as threads.\n", id, id_sys);

    #pragma omp master
    {
      printf("Thread[%d][%lu]: Código Executado pela thread master.\n", id, (long int) pthread_self());
    }

    #pragma omp single
    {
      printf("Thread[%d][%lu]: Código Executado por uma das threads.\n", id, (long int) pthread_self());
    }

    if(omp_get_thread_num() == 3){
      printf("Thread[%d][%lu]: Código Executado pela thread de id: 3.\n", id, (long int) pthread_self());
    }

    #pragma omp critical
    {
      printf("Thread[%d][%lu]: Executando a região crítica.\n", id, (long int) pthread_self());
      printf("Thread[%d][%lu]: Antes... valor: %d\n", id, (long int) pthread_self(), valor);
      valor = valor + id;
      printf("Thread[%d][%lu]: Depois... valor: %d\n", id, (long int) pthread_self(), valor);
    }

    printf("Thread[%d][%lu]: Barreira.\n", id, (long int) pthread_self());
    #pragma omp barrier
    printf("Thread[%d][%lu]: Depois da barreira.\n", id, (long int) pthread_self());

  }
  printf("Thread[%d][%lu]: Depois da Região Paralela.\n", omp_get_thread_num(), (long int) pthread_self());

  return 0;
}
