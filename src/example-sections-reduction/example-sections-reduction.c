#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, id;
  int sum = 0;
  
  fprintf(stdout, "Thread[%d][%lu]: Antes da Região Paralela.\n", omp_get_thread_num(), (long int)pthread_self());
  
  #pragma omp parallel num_threads(8) private(id)
  {
  	id = omp_get_thread_num();
    #pragma omp sections reduction(+:sum)
    {
      #pragma omp section
      {
        fprintf(stdout, "   Thread[%lu,%lu]: Trabalhando na seção 1.\n", id, (long int) pthread_self());
        for(i=0; i<1024;i++){
          sum += i;  
        } 
      }
      
      #pragma omp section
      {
        fprintf(stdout, "   Thread[%lu,%lu]: Trabalhando na seção 2.\n", id, (long int) pthread_self());
        for(i=0; i<1024;i++){
          sum += i;  
        }
      }
    }
  }

  fprintf(stdout, "Thread[%d][%lu]: Depois da Região Paralela.\n", omp_get_thread_num(), (long int)pthread_self());
  fprintf(stdout, "Thread[%d][%lu]: sum: %d\n", omp_get_thread_num(), (long int)pthread_self(), sum);
    
  return 0;
}
