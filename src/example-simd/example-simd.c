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

#include <stdio.h>
#include <stdlib.h>

// Size of vectors.
#ifndef N
#define N 1048576
#endif
// Entrada e saída.
double h_a[N];
double h_b[N];
double h_c[N];

void init_array() {
  fprintf(stdout, "Inicializando os arrays.\n");
  int i;
  // Initialize vectors on host.
  for (i = 0; i < N; i++) {
    h_a[i] = 0.5;
    h_b[i] = 0.5;
  }
}

int main(int argc, char **argv) {
  int i;
  double res;
  /* Inicialização  dos vetores. */
  init_array();
  
  fprintf(stdout, "Thread[%lu,%lu]: Antes do simd.\n", (long int) omp_get_thread_num(), (long int) pthread_self());
  // #pragma omp simd simdlen(1024) reduction(+:res)
  #pragma omp simd
  for (i = 0; i < N; i++) {
    // res += h_a[i] * h_b[i];
    h_c[i] += h_a[i] * h_b[i];
  }

  fprintf(stdout, "Thread[%lu,%lu]: Depois do simd.\n", (long int) omp_get_thread_num(), (long int) pthread_self());

  fprintf(stdout, "Thread[%lu,%lu]: res: %g\n", (long int) omp_get_thread_num(), (long int) pthread_self(), res);

  return 0;
}
