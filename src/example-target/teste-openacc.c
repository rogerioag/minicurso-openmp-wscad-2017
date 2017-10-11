void vecaddgpu(float *restrict c, float *a, float *b, int n){ 
  #pragma acc kernels for present(c,a,b) 
  for( int i = 0; i < n; ++i ) 
    c[i] = a[i] + b[i]; 
}

int main( int argc, char* argv[] ){ 

  #pragma acc data copyin(a[0:n],b[0:n]) copyout(c[0:n]) 
  { 
    vecaddgpu(c, a, b, n); 
  }
  
  return 0;
}
