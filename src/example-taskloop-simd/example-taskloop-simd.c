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

/*void print_array() {
    int i;
    for (i = 0; i < N; i++) {
        fprintf(stdout, "h_c[%07d]: %f\n", i, h_c[i]);
    }
}

void check_result(){
    // Soma dos elementos do array C e divide por N, o valor deve ser igual a 1.
    int i;
    double sum = 0;
    fprintf(stdout, "Verificando o resultado.\n");  

    for (i = 0; i < N; i++) {
        sum += h_c[i];
    }

    fprintf(stdout, "Resultado Final: (%f, %f)\n", sum, (double)(sum / (double)N));
}*/


void func(){

  int i;

  #pragma omp taskloop simd num_tasks(4)
  for (i = 0; i < N; i++) {
    h_c[i] = h_a[i] * h_b[i];
  }
}

int main(int argc, char *argv[]) {

  init_array();

  fprintf(stdout, "Thread[%lu,%lu]: Antes da Região Paralela.\n", (long int) omp_get_thread_num(), (long int) pthread_self());

  #pragma omp parallel num_threads(4)
  {
    #pragma omp single
    {
      fprintf(stdout, "  Thread[%lu,%lu]: Antes das tasks.\n", (long int) omp_get_thread_num(), (long int) pthread_self());
      func();        
    }
  }

  fprintf(stdout, "Thread[%lu,%lu]: Depois da Região Paralela.\n", (long int) omp_get_thread_num(), (long int) pthread_self());

  /* Resultados. */
  // print_array();
  // check_result();
    
  return 0;
}
