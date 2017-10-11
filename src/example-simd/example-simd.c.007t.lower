
;; Function init_array (init_array, funcdef_no=2, decl_uid=3364, symbol_order=5)

init_array ()
{
  int i;
  struct _IO_FILE * stdout.0;

  stdout.0 = stdout;
  __builtin_fwrite ("Inicializando os arrays.\n", 1, 25, stdout.0);
  i = 0;
  goto <D.3368>;
  <D.3367>:
  h_a[i] = 5.0e-1;
  h_b[i] = 5.0e-1;
  i = i + 1;
  <D.3368>:
  if (i <= 1048575) goto <D.3367>; else goto <D.3369>;
  <D.3369>:
  return;
}



;; Function main (main, funcdef_no=3, decl_uid=3372, symbol_order=6)

main (int argc, char * * argv)
{
  int i;
  double res;
  int i;
  int D.3398;
  struct _IO_FILE * stdout.3;
  long int D.3396;
  int D.3395;
  long int D.3394;
  long unsigned int D.3393;
  struct _IO_FILE * stdout.2;
  long int D.3391;
  int D.3390;
  long int D.3389;
  long unsigned int D.3388;
  double D.3387;
  double D.3386;
  double D.3385;
  double D.3384;
  double D.3383;
  struct _IO_FILE * stdout.1;
  long int D.3381;
  int D.3380;
  long int D.3379;
  long unsigned int D.3378;

  init_array ();
  D.3378 = pthread_self ();
  D.3379 = (long int) D.3378;
  D.3380 = omp_get_thread_num ();
  D.3381 = (long int) D.3380;
  stdout.1 = stdout;
  fprintf (stdout.1, "Thread[%lu,%lu]: Antes do simd.\n", D.3381, D.3379);
  i = 0;
  #pragma omp simd linear(i:1)
  for (i = 0; i <= 1048575; i = i + 1)
  D.3383 = h_c[i];
  D.3384 = h_a[i];
  D.3385 = h_b[i];
  D.3386 = D.3384 * D.3385;
  D.3387 = D.3383 + D.3386;
  h_c[i] = D.3387;
  #pragma omp continue (i, i)
  if (i == 1048576) goto <D.3401>; else goto <D.3400>;
  <D.3401>:
  i = i;
  <D.3400>:
  #pragma omp return(nowait)
  D.3388 = pthread_self ();
  D.3389 = (long int) D.3388;
  D.3390 = omp_get_thread_num ();
  D.3391 = (long int) D.3390;
  stdout.2 = stdout;
  fprintf (stdout.2, "Thread[%lu,%lu]: Depois do simd.\n", D.3391, D.3389);
  D.3393 = pthread_self ();
  D.3394 = (long int) D.3393;
  D.3395 = omp_get_thread_num ();
  D.3396 = (long int) D.3395;
  stdout.3 = stdout;
  fprintf (stdout.3, "Thread[%lu,%lu]: res: %g\n", D.3396, D.3394, res);
  D.3398 = 0;
  goto <D.3402>;
  <D.3402>:
  return D.3398;
}


