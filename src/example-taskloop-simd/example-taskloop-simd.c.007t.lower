
;; Function init_array (init_array, funcdef_no=2, decl_uid=3556, cgraph_uid=2, symbol_order=5)

init_array ()
{
  int i;
  struct _IO_FILE * stdout.0;

  stdout.0 = stdout;
  __builtin_fwrite ("Inicializando os arrays.\n", 1, 25, stdout.0);
  i = 0;
  goto <D.3560>;
  <D.3559>:
  h_a[i] = 5.0e-1;
  h_b[i] = 5.0e-1;
  i = i + 1;
  <D.3560>:
  if (i <= 1048575) goto <D.3559>; else goto <D.3561>;
  <D.3561>:
  return;
}



;; Function func (func, funcdef_no=3, decl_uid=3562, cgraph_uid=3, symbol_order=6)

func ()
{
  int i;
  int D.3591;
  int D.3590;
  int i;
  double D.3573;
  double D.3572;
  double D.3571;
  int * D.3596;
  int i;
  int i.1;
  struct  .omp_data_o.3;
  long int D.3576;
  long int D.3575;

  #pragma omp taskloop num_tasks(4)
  for (i.1 = 0; i.1 <= 1048575; i.1 = i.1 + 1)
  .omp_data_o.3.i = &i;
  #pragma omp taskloop _looptemp_(D.3576) _looptemp_(D.3575) private(i.1) shared(i) [child fn: func._omp_fn.0 (.omp_data_o.3)]
  .omp_data_i = (struct  & restrict) &.omp_data_o.3;
  D.3582 = .omp_data_i->D.3581;
  D.3584 = .omp_data_i->D.3583;
  i.1 = 0;
  #pragma omp taskloop _looptemp_(D.3582) _looptemp_(D.3584) lastprivate(i)
  for (i.1 = 0; i.1 <= 1048575; i.1 = i.1 + 1)
  i = 0;
  #pragma omp simd _looptemp_(D.3590) _looptemp_(D.3591) linear(i:1)
  for (i = 0; i <= 1048575; i = i + 1)
  D.3571 = h_a[i];
  D.3572 = h_b[i];
  D.3573 = D.3571 * D.3572;
  h_c[i] = D.3573;
  #pragma omp continue (i, i)
  if (i == 1048576) goto <D.3593>; else goto <D.3592>;
  <D.3593>:
  i = i;
  <D.3592>:
  #pragma omp return(nowait)
  #pragma omp continue (i.1, i.1)
  if (i.1 == 1048576) goto <D.3595>; else goto <D.3594>;
  <D.3595>:
  D.3596 = .omp_data_i->i;
  *D.3596 = i;
  <D.3594>:
  #pragma omp return
  #pragma omp continue (0, 0)
  #pragma omp return
  .omp_data_o.3 = {CLOBBER};
  #pragma omp continue (i.1, i.1)
  #pragma omp return
  return;
}



;; Function main (main, funcdef_no=4, decl_uid=3567, cgraph_uid=4, symbol_order=7)

main (int argc, char * * argv)
{
  _Bool D.3637;
  int D.3629;
  struct _IO_FILE * stdout.6;
  long int D.3627;
  int D.3626;
  long int D.3625;
  long unsigned int D.3624;
  struct _IO_FILE * stdout.4;
  long int D.3617;
  int D.3616;
  long int D.3615;
  long unsigned int D.3614;

  init_array ();
  D.3614 = pthread_self ();
  D.3615 = (long int) D.3614;
  D.3616 = omp_get_thread_num ();
  D.3617 = (long int) D.3616;
  stdout.4 = stdout;
  fprintf (stdout.4, "Thread[%lu,%lu]: Before parallel region.\n", D.3617, D.3615);
  #pragma omp parallel num_threads(4) [child fn: main._omp_fn.1 (???)]
  #pragma omp single
  D.3637 = __builtin_GOMP_single_start ();
  if (D.3637 == 1) goto <D.3635>; else goto <D.3636>;
  <D.3635>:
  D.3619 = pthread_self ();
  D.3620 = (long int) D.3619;
  D.3621 = omp_get_thread_num ();
  D.3622 = (long int) D.3621;
  stdout.5 = stdout;
  fprintf (stdout.5, "  Thread[%lu,%lu]: Before tasks.\n", D.3622, D.3620);
  func ();
  <D.3636>:
  #pragma omp return
  #pragma omp return
  D.3624 = pthread_self ();
  D.3625 = (long int) D.3624;
  D.3626 = omp_get_thread_num ();
  D.3627 = (long int) D.3626;
  stdout.6 = stdout;
  fprintf (stdout.6, "Thread[%lu,%lu]: After parallel region.\n", D.3627, D.3625);
  D.3629 = 0;
  goto <D.3638>;
  D.3629 = 0;
  goto <D.3638>;
  <D.3638>:
  return D.3629;
}


