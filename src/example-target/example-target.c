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


// Entrada e saída.
float *h_a;
float *h_b;
float *h_c;

int n = 0;

#define THRESHOLD 1024
	
void vecaddgpu(float *restrict c, float *a, float *b){
  #pragma omp target data map(to: a[0:n], b[:n]) map(from: c[0:n]) if(n>THRESHOLD)
  {
    #pragma omp target if(n>THRESHOLD)
    #pragma omp parallel for if(n>THRESHOLD)
    for( int i = 0; i < n; ++i ) 
      c[i] = a[i] + b[i]; 
  }
}

void init_array() {
    fprintf(stdout, "Inicializando os arrays.\n");
    int i;
    // Initialize vectors on host.
    for (i = 0; i < n; i++) {
        h_a[i] = 0.5;
        h_b[i] = 0.5;
    }
}

/*void print_array() {
    int i;
    for (i = 0; i < N; i++) {
        fprintf(stdout, "h_c[%07d]: %f\n", i, h_c[i]);
    }
}*/

/*void check_result(){
    // Soma dos elementos do array C e divide por N, o valor deve ser igual a 1.
    int i;
    float sum = 0;
    fprintf(stdout, "Verificando o resultado.\n");  

    for (i = 0; i < n; i++) {
        sum += h_c[i];
    }

    fprintf(stdout, "Resultado Final: (%f, %f)\n", sum, (float)(sum / (float)n));
}*/

int main(int argc, char *argv[]) {
    int i;

    n = atoi(argv[1]);

    h_a = (float*) malloc(n*sizeof(float));
    h_b = (float*) malloc(n*sizeof(float));
    h_c = (float*) malloc(n*sizeof(float));

    /* Inicialização  dos vetores. */
    init_array();

    vecaddgpu(h_c, h_a, h_b);

    /* Resultados. */
    // print_array();
    // check_result();

    return 0;
}
