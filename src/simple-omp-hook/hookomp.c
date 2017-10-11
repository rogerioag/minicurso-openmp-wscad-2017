#include "hookomp.h"

/* ------------------------------------------------------------- */
/* Test function.                                                */
void foo(void) {
	puts("Hello, I'm a shared library.\n");
}

/* ------------------------------------------------------------- */
/* barrier.c                                                     */
/* ------------------------------------------------------------- */
void GOMP_barrier (void) {
	PRINT_FUNC_NAME;
	
	GET_RUNTIME_FUNCTION(lib_GOMP_barrier, "GOMP_barrier");

	TRACE("[hookomp]: Thread [%lu] is executing barrier.\n", (unsigned long int) pthread_self());

	TRACE("[GOMP_1.0] GOMP_barrier@GOMP_1.0.\n");
	lib_GOMP_barrier();
}

/* ------------------------------------------------------------- */
bool GOMP_barrier_cancel (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_barrier_cancel, "GOMP_barrier_cancel");
	TRACE("[GOMP_1.0] GOMP_barrier_cancel@GOMP_1.0.\n");
	
	bool result = lib_GOMP_barrier_cancel();
	
	return result;
}

/* ------------------------------------------------------------- */
/* critical.c 													 */
/* ------------------------------------------------------------- */
void GOMP_critical_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_start, "GOMP_critical_start");
	TRACE("[GOMP_1.0] GOMP_critical_start@GOMP_1.0.\n");
	
	lib_GOMP_critical_start();
}

/* ------------------------------------------------------------- */
void GOMP_critical_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_end, "GOMP_critical_end");
	TRACE("[GOMP_1.0] GOMP_critical_end@GOMP_1.0.\n");
	
	lib_GOMP_critical_end();
}

/* ------------------------------------------------------------- */
void GOMP_critical_name_start (void **pptr){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_name_start, "GOMP_critical_name_start");
	TRACE("[GOMP_1.0] GOMP_critical_name_start@GOMP_1.0.\n");
	
	lib_GOMP_critical_name_start(pptr);
}

/* ------------------------------------------------------------- */
void GOMP_critical_name_end (void **pptr){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_critical_name_end, "GOMP_critical_name_end");
	TRACE("[GOMP_1.0] GOMP_critical_name_end@GOMP_1.0.\n");
	
	lib_GOMP_critical_name_end(pptr);
}

/* ------------------------------------------------------------- */
void GOMP_atomic_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_atomic_start, "GOMP_atomic_start");
	TRACE("[GOMP_1.0] GOMP_atomic_start@GOMP_1.0.\n");
	
	lib_GOMP_atomic_start();
}

/* ------------------------------------------------------------- */
void GOMP_atomic_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_atomic_end, "GOMP_atomic_end");
	TRACE("[GOMP_1.0] GOMP_atomic_end@GOMP_1.0.\n");
	
	lib_GOMP_atomic_end();
}

/* ------------------------------------------------------------- */
/* loop.c                                                        */
/* ------------------------------------------------------------- */

bool GOMP_loop_static_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_static_start, "GOMP_loop_static_start");
	TRACE("[GOMP_1.0] GOMP_loop_static_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_static_start(start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_dynamic_start (long start, long end, long incr, long chunk_size,
			 long *istart, long *iend){
	PRINT_FUNC_NAME;

	TRACE("Thread [%lu] is executing GOMP_loop_dynamic_start.\n", (unsigned long int) pthread_self());

	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_dynamic_start, "GOMP_loop_dynamic_start");

	PRE_GOMP_loop_dynamic_start();

	TRACE("[GOMP] GOMP_loop_dynamic_start@GOMP:[%p]\n", (void* )lib_GOMP_loop_dynamic_start);
	bool result = lib_GOMP_loop_dynamic_start(start, end, incr, chunk_size, istart, iend);

	POST_GOMP_loop_dynamic_start();
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_guided_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_guided_start, "GOMP_loop_guided_start");
	TRACE("[GOMP_1.0] GOMP_loop_guided_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_guided_start(start, end, incr, chunk_size, istart, iend);
	
	return result;
}
/* ------------------------------------------------------------- */
bool GOMP_loop_runtime_start (long start, long end, long incr,
			 long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_runtime_start, "GOMP_loop_runtime_start");
	TRACE("[GOMP_1.0] GOMP_loop_runtime_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_runtime_start(start, end, incr, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_static_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_static_start, "GOMP_loop_ordered_static_start");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_static_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ordered_static_start(start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_dynamic_start (long start, long end, long incr,
				 long chunk_size, long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_dynamic_start, "GOMP_loop_ordered_dynamic_start");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_dynamic_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ordered_dynamic_start(start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_guided_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_guided_start, "GOMP_loop_ordered_guided_start");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_guided_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ordered_guided_start(start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_runtime_start (long start, long end, long incr,
				 long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_runtime_start, "GOMP_loop_ordered_runtime_start");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_runtime_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ordered_runtime_start(start, end, incr, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_static_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_static_next, "GOMP_loop_static_next");
	TRACE("[GOMP_1.0] GOMP_loop_static_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_static_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_dynamic_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	TRACE("Thread [%lu] is executing GOMP_loop_dynamic_next.\n", (unsigned long int) pthread_self());

	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_dynamic_next, "GOMP_loop_dynamic_next");
	
	PRE_GOMP_loop_dynamic_next();

	TRACE("[GOMP] GOMP_loop_dynamic_next@GOMP:[%p]\n", (void* )lib_GOMP_loop_dynamic_next);
	
	bool result = lib_GOMP_loop_dynamic_next(istart, iend);

	POST_GOMP_loop_dynamic_next(*istart, *iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_guided_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_guided_next, "GOMP_loop_guided_next");
	TRACE("[GOMP_1.0] GOMP_loop_guided_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_guided_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_runtime_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_runtime_next, "GOMP_loop_runtime_next");
	TRACE("[GOMP_1.0] GOMP_loop_runtime_next@GOMP_1.0.\n");

	long int thread_executing_function_next = (long int) pthread_self();

	TRACE("[hookomp]: Thread [%lu] is calling %s.\n", thread_executing_function_next, __FUNCTION__);

	TRACE("[hookomp]: [After]-> GOMP_loop_runtime_next -- Tid[%lu] istart: %ld iend: %ld.\n", thread_executing_function_next, *istart, *iend);

	bool result = lib_GOMP_loop_runtime_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_static_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_static_next, "GOMP_loop_ordered_static_next");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_static_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ordered_static_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_dynamic_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_dynamic_next, "GOMP_loop_ordered_dynamic_next");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_dynamic_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ordered_dynamic_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_guided_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_guided_next, "GOMP_loop_ordered_guided_next");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_guided_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ordered_guided_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ordered_runtime_next (long *istart, long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ordered_runtime_next, "GOMP_loop_ordered_runtime_next");
	TRACE("[GOMP_1.0] GOMP_loop_ordered_runtime_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ordered_runtime_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_static_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_static_start, "GOMP_parallel_loop_static_start");

	TRACE("[GOMP_1.0] GOMP_parallel_loop_static_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_static_start[%p]\n", (void* )lib_GOMP_parallel_loop_static_start);

	lib_GOMP_parallel_loop_static_start(fn, data, num_threads, start, end, incr, chunk_size);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_dynamic_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr, long chunk_size){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_dynamic_start, "GOMP_parallel_loop_dynamic_start");

	TRACE("[GOMP_1.0] GOMP_parallel_loop_dynamic_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_dynamic_start[%p]\n", (void* )lib_GOMP_parallel_loop_dynamic_start);

	lib_GOMP_parallel_loop_dynamic_start(fn, data, num_threads, start, end, incr, chunk_size);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_guided_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_guided_start, "GOMP_parallel_loop_guided_start");

	TRACE("[GOMP_1.0] GOMP_parallel_loop_guided_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_guided_start[%p]\n", (void* )lib_GOMP_parallel_loop_guided_start);

	lib_GOMP_parallel_loop_guided_start(fn, data, num_threads, start, end, incr, chunk_size);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_runtime_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_runtime_start, "GOMP_parallel_loop_runtime_start");

	TRACE("[GOMP_1.0] GOMP_parallel_loop_runtime_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_runtime_start[%p]\n", (void* )lib_GOMP_parallel_loop_runtime_start);

	lib_GOMP_parallel_loop_runtime_start(fn, data, num_threads, start, end, incr);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_static (void (*fn) (void *), void *data,
			   unsigned num_threads, long start, long end,
			   long incr, long chunk_size, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_static, "GOMP_parallel_loop_static");

	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_static[%p]\n", (void* )lib_GOMP_parallel_loop_static);

	lib_GOMP_parallel_loop_static(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_dynamic (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, long chunk_size, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_dynamic, "GOMP_parallel_loop_dynamic");

	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_dynamic[%p]\n", (void* )lib_GOMP_parallel_loop_dynamic);

	lib_GOMP_parallel_loop_dynamic(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_guided (void (*fn) (void *), void *data,
			  unsigned num_threads, long start, long end,
			  long incr, long chunk_size, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_guided, "GOMP_parallel_loop_guided");

	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_guided[%p]\n", (void* )lib_GOMP_parallel_loop_guided);

	lib_GOMP_parallel_loop_guided(fn, data, num_threads, start, end, incr, chunk_size, flags);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_loop_runtime (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_loop_runtime, "GOMP_parallel_loop_runtime");

	TRACE("[GOMP_1.0] lib_GOMP_parallel_loop_runtime[%p]\n", (void* )lib_GOMP_parallel_loop_runtime);

	lib_GOMP_parallel_loop_runtime(fn, data, num_threads, start, end, incr, flags);
}

/* ------------------------------------------------------------- */
void GOMP_loop_end (void){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end, "GOMP_loop_end");

	TRACE("[GOMP_1.0] lib_GOMP_loop_end[%p]\n", (void* )lib_GOMP_loop_end);

	lib_GOMP_loop_end();
}
/* ------------------------------------------------------------- */
void GOMP_loop_end_nowait (void){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end_nowait, "GOMP_loop_end_nowait");

	TRACE("[GOMP_1.0] lib_GOMP_loop_end_nowait[%p]\n", (void* )GOMP_loop_end_nowait);

	TRACE("[hookomp]: Thread [%lu] is calling %s.\n", (long int) pthread_self(), __FUNCTION__);

	lib_GOMP_loop_end_nowait();
}

/* ------------------------------------------------------------- */
bool GOMP_loop_end_cancel (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_end_cancel, "GOMP_loop_end_cancel");
	TRACE("[GOMP_1.0] GOMP_loop_end_cancel@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_end_cancel();
	
	return result;
}

/* ------------------------------------------------------------- */
/* loop_ull.c                                                    */
/* ------------------------------------------------------------- */
bool GOMP_loop_ull_static_start (bool up, unsigned long long start, unsigned long long end,
			    unsigned long long incr, unsigned long long chunk_size,
			    unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_static_start, "GOMP_loop_ull_static_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_static_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_static_start(up, start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_dynamic_start (bool up, unsigned long long start, unsigned long long end,
			     unsigned long long incr, unsigned long long chunk_size,
			     unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_dynamic_start, "GOMP_loop_ull_dynamic_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_dynamic_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_guided_start (bool up, unsigned long long start, unsigned long long end,
			    unsigned long long incr, unsigned long long chunk_size,
			    unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_guided_start, "GOMP_loop_ull_guided_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_guided_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_guided_start(up, start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_runtime_start (bool up, unsigned long long start, unsigned long long end,
			     unsigned long long incr, unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_runtime_start, "GOMP_loop_ull_runtime_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_runtime_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_runtime_start(up, start, end, incr, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_static_start (bool up, unsigned long long start, unsigned long long end,
				    unsigned long long incr, unsigned long long chunk_size,
				    unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_static_start, "GOMP_loop_ull_ordered_static_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_static_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_ordered_static_start(up, start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_dynamic_start (bool up, unsigned long long start, unsigned long long end,
				     unsigned long long incr, unsigned long long chunk_size,
				     unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_dynamic_start, "GOMP_loop_ull_ordered_dynamic_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_dynamic_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_ordered_dynamic_start(up, start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_guided_start (bool up, unsigned long long start, unsigned long long end,
				    unsigned long long incr, unsigned long long chunk_size,
				    unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_guided_start, "GOMP_loop_ull_ordered_guided_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_guided_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_ordered_guided_start(up, start, end, incr, chunk_size, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_runtime_start (bool up, unsigned long long start, unsigned long long end,
				     unsigned long long incr, unsigned long long *istart,
				     unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_runtime_start, "GOMP_loop_ull_ordered_runtime_start");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_runtime_start@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_ordered_runtime_start(up, start, end, incr, istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_static_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_static_next, "GOMP_loop_ull_static_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_static_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_static_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_dynamic_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_dynamic_next, "GOMP_loop_ull_dynamic_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_dynamic_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_dynamic_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_guided_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_guided_next, "GOMP_loop_ull_guided_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_guided_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_guided_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_runtime_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_runtime_next, "GOMP_loop_ull_runtime_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_runtime_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_runtime_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_static_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_static_next, "GOMP_loop_ull_ordered_static_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_static_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_ordered_static_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_dynamic_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_dynamic_next, "GOMP_loop_ull_ordered_dynamic_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_dynamic_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_ordered_dynamic_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_guided_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_guided_next, "GOMP_loop_ull_ordered_guided_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_guided_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_ordered_guided_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_loop_ull_ordered_runtime_next (unsigned long long *istart, unsigned long long *iend){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_loop_ull_ordered_runtime_next, "GOMP_loop_ull_ordered_runtime_next");
	TRACE("[GOMP_1.0] GOMP_loop_ull_ordered_runtime_next@GOMP_1.0.\n");
	
	bool result = lib_GOMP_loop_ull_ordered_runtime_next(istart, iend);
	
	return result;
}

/* ------------------------------------------------------------- */
/* ordered.c                                                     */
/* ------------------------------------------------------------- */
void GOMP_ordered_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_ordered_start, "GOMP_ordered_start");
	TRACE("[GOMP_1.0] GOMP_ordered_start@GOMP_1.0.\n");
	
	lib_GOMP_ordered_start();
}

/* ------------------------------------------------------------- */
void GOMP_ordered_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_ordered_end, "GOMP_ordered_end");
	TRACE("[GOMP_1.0] GOMP_ordered_end@GOMP_1.0.\n");
	
	lib_GOMP_ordered_end();
}

/* ------------------------------------------------------------- */
/* parallel.c                                                    */
/* ------------------------------------------------------------- */
/* Function to intercept GOMP_parallel_start                     */
void GOMP_parallel_start (void (*fn) (void *), void *data, unsigned num_threads){
	PRINT_FUNC_NAME;

	TRACE("Thread [%lu] is executing GOMP_parallel_start.\n", (unsigned long int) pthread_self());

	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_start, "GOMP_parallel_start");

	PRE_GOMP_parallel_start();

	TRACE("[GOMP] lib_GOMP_parallel_start@GOMP:[%p]\n", (void* )lib_GOMP_parallel_start);
	lib_GOMP_parallel_start(fn, data, num_threads);

	POST_GOMP_parallel_start();
}

/* ------------------------------------------------------------- */
/* Function to intercept GOMP_parallel_end                       */
void GOMP_parallel_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_end, "GOMP_parallel_end");

	PRE_GOMP_parallel_end();

	TRACE("[GOMP] GOMP_parallel_end@GOMP:[%p]\n", (void* )lib_GOMP_parallel_end);
    lib_GOMP_parallel_end();

    POST_GOMP_parallel_end();
}

/* ------------------------------------------------------------- */
void GOMP_parallel (void (*fn) (void *), void *data, unsigned num_threads, unsigned int flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel, "GOMP_parallel");

	TRACE("[GOMP_1.0] GOMP_parallel@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel[%p]\n", (void* )lib_GOMP_parallel);

	lib_GOMP_parallel(fn, data, num_threads, flags);
}

/* ------------------------------------------------------------- */
bool GOMP_cancel (int which, bool do_cancel){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_cancel, "GOMP_cancel");
	TRACE("[GOMP_1.0] GOMP_cancel@GOMP_1.0.\n");
	
	bool result = lib_GOMP_cancel(which, do_cancel);
	
	return result;
}

/* ------------------------------------------------------------- */
bool GOMP_cancellation_point (int which){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_cancellation_point, "GOMP_cancellation_point");
	TRACE("[GOMP_1.0] GOMP_cancellation_point@GOMP_1.0.\n");
	
	bool result = lib_GOMP_cancellation_point(which);
	
	return result;
}

/* ------------------------------------------------------------- */
/* task.c */
/* ------------------------------------------------------------- */
void GOMP_task (void (*fn) (void *), void *data, void (*cpyfn) (void *, void *),
	   long arg_size, long arg_align, bool if_clause, unsigned flags,
	   void **depend){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_task, "GOMP_task");

	TRACE("[GOMP_1.0] GOMP_task@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_task[%p]\n", (void* )lib_GOMP_task);

	PRE_GOMP_task();

	lib_GOMP_task(fn, data, cpyfn, arg_size, arg_align, if_clause, flags, depend);

	POST_GOMP_task();
}

/* ------------------------------------------------------------- */
void GOMP_taskwait (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_taskwait, "GOMP_taskwait");
	TRACE("[GOMP_1.0] GOMP_taskwait@GOMP_1.0.\n");
	
	lib_GOMP_taskwait();
}

/* ------------------------------------------------------------- */
void GOMP_taskyield (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_taskyield, "GOMP_taskyield");
	TRACE("[GOMP_1.0] GOMP_taskyield@GOMP_1.0.\n");
	
	lib_GOMP_taskyield();
}

/* ------------------------------------------------------------- */
void GOMP_taskgroup_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_taskgroup_start, "GOMP_taskgroup_start");
	TRACE("[GOMP_1.0] GOMP_taskgroup_start@GOMP_1.0.\n");
	
	lib_GOMP_taskgroup_start();
}

/* ------------------------------------------------------------- */
void GOMP_taskgroup_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_taskgroup_end, "GOMP_taskgroup_end");
	TRACE("[GOMP_1.0] GOMP_taskgroup_end@GOMP_1.0.\n");
	
	lib_GOMP_taskgroup_end();
}

/* ------------------------------------------------------------- */
/* sections.c */
/* ------------------------------------------------------------- */
unsigned GOMP_sections_start (unsigned count){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_start, "GOMP_sections_start");
	TRACE("[GOMP_1.0] GOMP_sections_start@GOMP_1.0.\n");
	
	unsigned result = lib_GOMP_sections_start(count);
	
	return result;
}

/* ------------------------------------------------------------- */
unsigned GOMP_sections_next (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_next, "GOMP_sections_next");
	TRACE("[GOMP_1.0] GOMP_sections_next@GOMP_1.0.\n");
	
	unsigned result = lib_GOMP_sections_next();
	
	return result;
}

/* ------------------------------------------------------------- */
void GOMP_parallel_sections_start (void (*fn) (void *), void *data,
			      unsigned num_threads, unsigned count){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_sections_start, "GOMP_parallel_sections_start");

	TRACE("[GOMP_1.0] GOMP_parallel_sections_start@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GOMP_parallel_sections_start[%p]\n", (void* )lib_GOMP_parallel_sections_start);

	lib_GOMP_parallel_sections_start(fn, data, num_threads, count);
}

/* ------------------------------------------------------------- */
void GOMP_parallel_sections (void (*fn) (void *), void *data,
			unsigned num_threads, unsigned count, unsigned flags){
	PRINT_FUNC_NAME;

  	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_parallel_sections, "GOMP_parallel_sections");

	TRACE("[GOMP_1.0] GOMP_parallel_sections@GOMP_1.0.[%p]\n", (void* )fn);
	
	TRACE("[GOMP_1.0] lib_GGOMP_parallel_sections[%p]\n", (void* )lib_GOMP_parallel_sections);

	lib_GOMP_parallel_sections(fn, data, num_threads, count, flags);
}

/* ------------------------------------------------------------- */
void GOMP_sections_end (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end, "GOMP_sections_end");
	TRACE("[GOMP_1.0] GOMP_sections_end@GOMP_1.0.\n");
	
	lib_GOMP_sections_end();
}
	
/* ------------------------------------------------------------- */
void GOMP_sections_end_nowait (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end_nowait, "GOMP_sections_end_nowait");
	TRACE("[GOMP_1.0] GOMP_sections_end_nowait@GOMP_1.0.\n");
	
	lib_GOMP_sections_end_nowait();
}
	
/* ------------------------------------------------------------- */
bool GOMP_sections_end_cancel (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_sections_end_cancel, "GOMP_sections_end_cancel");
	TRACE("[GOMP_1.0] GOMP_sections_end_cancel@GOMP_1.0.\n");
	
	bool result = lib_GOMP_sections_end_cancel();
	
	return result;
}

/* ------------------------------------------------------------- */
/* single.c */
/* ------------------------------------------------------------- */
bool GOMP_single_start (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_single_start, "GOMP_single_start");
	
   TRACE("[hookomp]: Testing single start[%lu].\n", (unsigned long int) pthread_self());

   TRACE("[GOMP_1.0] GOMP_single_start@GOMP_1.0.\n");
   bool result = lib_GOMP_single_start();

   return result;
}

/* ------------------------------------------------------------- */
void *GOMP_single_copy_start (void){
	PRINT_FUNC_NAME;

	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_single_copy_start, "GOMP_single_copy_start");
	TRACE("[GOMP_1.0] GOMP_single_copy_start@GOMP_1.0.\n");
	
	void *result;

	result = lib_GOMP_single_copy_start();

	return result;
}

/* ------------------------------------------------------------- */
void GOMP_single_copy_end (void *data){

	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_single_copy_end, "GOMP_single_copy_end");
	TRACE("[GOMP_1.0] GOMP_single_copy_end@GOMP_1.0.\n");
	
	lib_GOMP_single_copy_end(data);
}

/* ------------------------------------------------------------- */
/* target.c */
/* ------------------------------------------------------------- */

void GOMP_target (int device, void (*fn) (void *), const void *unused,
	     size_t mapnum, void **hostaddrs, size_t *sizes,
	     unsigned char *kinds){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_target, "GOMP_target");
	TRACE("[GOMP_1.0] GOMP_target@GOMP_1.0.\n");
	
	lib_GOMP_target(device, fn, unused, mapnum, hostaddrs, sizes, kinds);
}

/* ------------------------------------------------------------- */
void GOMP_target_data (int device, const void *unused, size_t mapnum,
		  void **hostaddrs, size_t *sizes, unsigned char *kinds){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_target_data, "GOMP_target_data");
	TRACE("[GOMP_1.0] GOMP_target_data@GOMP_1.0.\n");
	
	lib_GOMP_target_data(device, unused, mapnum, hostaddrs, sizes, kinds);
}

/* ------------------------------------------------------------- */
void GOMP_target_end_data (void){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_target_end_data, "GOMP_target_end_data");
	TRACE("[GOMP_1.0] GOMP_target_end_data@GOMP_1.0.\n");
	
	lib_GOMP_target_end_data();
}

/* ------------------------------------------------------------- */
void GOMP_target_update (int device, const void *unused, size_t mapnum,
		    void **hostaddrs, size_t *sizes, unsigned char *kinds){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_target_update, "GOMP_target_update");
	TRACE("[GOMP_1.0] GOMP_target_update@GOMP_1.0.\n");
	
	lib_GOMP_target_update(device, unused, mapnum, hostaddrs, sizes, kinds);
}

/* ------------------------------------------------------------- */
void GOMP_teams (unsigned int num_teams, unsigned int thread_limit){
	PRINT_FUNC_NAME;
	
	// Retrieve the OpenMP runtime function.
	GET_RUNTIME_FUNCTION(lib_GOMP_teams, "GOMP_teams");
	TRACE("[GOMP_1.0] GOMP_teams@GOMP_1.0.\n");
	
	lib_GOMP_teams(num_teams, thread_limit);
}

/* ------------------------------------------------------------- */
