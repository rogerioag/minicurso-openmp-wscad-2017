#ifndef hookomp_h__
#define hookomp_h__
 
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include "debug.h"

#include "prepostdef.h"

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#define omp_get_num_threads() 1
#endif

#define  PRINT_ERROR()					\
  do {									\
    char * error;						\
    if ((error = dlerror()) != NULL)  {	\
      fputs(error, stderr);				\
    }									\
  }while(0)

#define GET_RUNTIME_FUNCTION(hook_func_pointer, func_name)									\
  do {																						\
    if (hook_func_pointer) break;															\
    void *__handle = RTLD_NEXT;																\
    hook_func_pointer = (typeof(hook_func_pointer)) (uintptr_t) dlsym(__handle, func_name);	\
    PRINT_ERROR();																			\
  } while(0)

/* Tipo para o ponteiro de função. */
typedef void (*op_func) (void);

/* Ponteiros para as funções que serão recuperadas pela macro get runtime function.*/

	/* barrier.c */

	void (*lib_GOMP_barrier)(void);
	bool (*lib_GOMP_barrier_cancel)(void);

	/* critical.c */

	void (*lib_GOMP_critical_start) (void);
	void (*lib_GOMP_critical_end) (void);
	void (*lib_GOMP_critical_name_start) (void **pptr);
	void (*lib_GOMP_critical_name_end) (void **pptr);
	void (*lib_GOMP_atomic_start) (void);
	void (*lib_GOMP_atomic_end) (void);

	/* loop.c */

	bool (*lib_GOMP_loop_static_start) (long start, long end, long incr, long chunk_size, 
			 long *istart, long *iend);

	bool (*lib_GOMP_loop_dynamic_start) (long start, long end, long incr, long chunk_size, 
			 long *istart, long *iend);

	bool (*lib_GOMP_loop_guided_start) (long start, long end, long incr, long chunk_size,
			long *istart, long *iend);

	bool (*lib_GOMP_loop_runtime_start) (long start, long end, long incr,
			 long *istart, long *iend);

	bool (*lib_GOMP_loop_ordered_static_start) (long start, long end, long incr,
				long chunk_size, long *istart, long *iend);

	bool (*lib_GOMP_loop_ordered_dynamic_start) (long start, long end, long incr,
				 long chunk_size, long *istart, long *iend);

	bool (*lib_GOMP_loop_ordered_guided_start) (long start, long end, long incr,
				long chunk_size, long *istart, long *iend);

	bool (*lib_GOMP_loop_ordered_runtime_start) (long start, long end, long incr,
				 long *istart, long *iend);

	bool (*lib_GOMP_loop_static_next) (long *istart, long *iend);

	bool (*lib_GOMP_loop_dynamic_next) (long *istart, long *iend);

	bool (*lib_GOMP_loop_guided_next) (long *istart, long *iend);

	bool (*lib_GOMP_loop_runtime_next) (long *istart, long *iend);

	bool (*lib_GOMP_loop_ordered_static_next) (long *istart, long *iend);

	bool (*lib_GOMP_loop_ordered_dynamic_next) (long *istart, long *iend);

	bool (*lib_GOMP_loop_ordered_guided_next) (long *istart, long *iend);

	bool (*lib_GOMP_loop_ordered_runtime_next) (long *istart, long *iend);

	void (*lib_GOMP_parallel_loop_static_start) (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size);

	void (*lib_GOMP_parallel_loop_dynamic_start) (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr, long chunk_size);

	void (*lib_GOMP_parallel_loop_guided_start) (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size);

	void (*lib_GOMP_parallel_loop_runtime_start) (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr);

	void (*lib_GOMP_parallel_loop_static) (void (*fn) (void *), void *data,
			   unsigned num_threads, long start, long end,
			   long incr, long chunk_size, unsigned flags);

	void (*lib_GOMP_parallel_loop_dynamic) (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, long chunk_size, unsigned flags);

	void (*lib_GOMP_parallel_loop_guided) (void (*fn) (void *), void *data,
			  unsigned num_threads, long start, long end,
			  long incr, long chunk_size, unsigned flags);
	
	void (*lib_GOMP_parallel_loop_runtime) (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, unsigned flags);
	
	void (*lib_GOMP_loop_end) (void);
	void (*lib_GOMP_loop_end_nowait) (void);
	bool (*lib_GOMP_loop_end_cancel) (void);

	/* loop_ull.c */

	bool (*lib_GOMP_loop_ull_static_start) (bool up, unsigned long long start, unsigned long long end,
			    unsigned long long incr, unsigned long long chunk_size,
			    unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_dynamic_start) (bool up, unsigned long long start, unsigned long long end,
			     unsigned long long incr, unsigned long long chunk_size,
			     unsigned long long *istart, unsigned long long *iend);


	bool (*lib_GOMP_loop_ull_guided_start) (bool up, unsigned long long start, unsigned long long end,
			    unsigned long long incr, unsigned long long chunk_size,
			    unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_runtime_start) (bool up, unsigned long long start, unsigned long long end,
			     unsigned long long incr, unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_ordered_static_start) (bool up, unsigned long long start, unsigned long long end,
				    unsigned long long incr, unsigned long long chunk_size,
				    unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_ordered_dynamic_start) (bool up, unsigned long long start, unsigned long long end,
				     unsigned long long incr, unsigned long long chunk_size,
				     unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_ordered_guided_start) (bool up, unsigned long long start, unsigned long long end,
				    unsigned long long incr, unsigned long long chunk_size,
				    unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_ordered_runtime_start) (bool up, unsigned long long start, unsigned long long end,
				     unsigned long long incr, unsigned long long *istart,
				     unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_static_next) (unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_dynamic_next) (unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_guided_next) (unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_runtime_next) (unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_ordered_static_next) (unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_ordered_dynamic_next) (unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_ordered_guided_next) (unsigned long long *istart, unsigned long long *iend);

	bool (*lib_GOMP_loop_ull_ordered_runtime_next) (unsigned long long *istart, unsigned long long *iend);

	/* ordered.c */

	void (*lib_GOMP_ordered_start) (void);
	void (*lib_GOMP_ordered_end) (void);

	/* parallel.c */

	void (*lib_GOMP_parallel_start) (void (*fn) (void *), void *data, unsigned num_threads);
	void (*lib_GOMP_parallel_end) (void);

	void (*lib_GOMP_parallel) (void (*fn) (void *), void *data, unsigned num_threads, unsigned int flags);
	bool (*lib_GOMP_cancel) (int which, bool do_cancel);
	bool (*lib_GOMP_cancellation_point) (int which);

	/* task.c */

	void (*lib_GOMP_task) (void (*fn) (void *), void *data, void (*cpyfn) (void *, void *),
	   long arg_size, long arg_align, bool if_clause, unsigned flags,
	   void **depend);

	void (*lib_GOMP_taskwait) (void);
	void (*lib_GOMP_taskyield) (void);
	void (*lib_GOMP_taskgroup_start) (void);
	void (*lib_GOMP_taskgroup_end) (void);

	/* sections.c */

	unsigned (*lib_GOMP_sections_start) (unsigned count);

	unsigned (*lib_GOMP_sections_next) (void);

	void (*lib_GOMP_parallel_sections_start) (void (*fn) (void *), void *data,
			      unsigned num_threads, unsigned count);

	void (*lib_GOMP_parallel_sections) (void (*fn) (void *), void *data,
			unsigned num_threads, unsigned count, unsigned flags);

	void (*lib_GOMP_sections_end) (void);
	
	void (*lib_GOMP_sections_end_nowait) (void);
	
	bool (*lib_GOMP_sections_end_cancel) (void);

	/* single.c */

	bool (*lib_GOMP_single_start) (void);

	void *(*lib_GOMP_single_copy_start) (void);

	void (*lib_GOMP_single_copy_end) (void *data);

	/* target.c */

	void (*lib_GOMP_target) (int device, void (*fn) (void *), const void *unused,
	     size_t mapnum, void **hostaddrs, size_t *sizes,
	     unsigned char *kinds);

	void (*lib_GOMP_target_data) (int device, const void *unused, size_t mapnum,
		  void **hostaddrs, size_t *sizes, unsigned char *kinds);

	void (*lib_GOMP_target_end_data) (void);

	void (*lib_GOMP_target_update) (int device, const void *unused, size_t mapnum,
		    void **hostaddrs, size_t *sizes, unsigned char *kinds);

	void (*lib_GOMP_teams) (unsigned int num_teams, unsigned int thread_limit);

#ifdef __cplusplus 
extern "C" {
#endif

	void foo(void);

	/* barrier.c */

	void GOMP_barrier (void);
	bool GOMP_barrier_cancel (void);

	/* critical.c */

	void GOMP_critical_start (void);
	void GOMP_critical_end (void);
	void GOMP_critical_name_start (void **pptr);
	void GOMP_critical_name_end (void **pptr);
	void GOMP_atomic_start (void);
	void GOMP_atomic_end (void);

	/* loop.c */

	bool GOMP_loop_static_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend);

	bool GOMP_loop_dynamic_start (long start, long end, long incr, long chunk_size,
			 long *istart, long *iend);

	bool GOMP_loop_guided_start (long start, long end, long incr, long chunk_size,
			long *istart, long *iend);

	bool GOMP_loop_runtime_start (long start, long end, long incr,
			 long *istart, long *iend);

	bool GOMP_loop_ordered_static_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend);

	bool GOMP_loop_ordered_dynamic_start (long start, long end, long incr,
				 long chunk_size, long *istart, long *iend);

	bool GOMP_loop_ordered_guided_start (long start, long end, long incr,
				long chunk_size, long *istart, long *iend);

	bool GOMP_loop_ordered_runtime_start (long start, long end, long incr,
				 long *istart, long *iend);

	bool GOMP_loop_static_next (long *istart, long *iend);

	bool GOMP_loop_dynamic_next (long *istart, long *iend);

	bool GOMP_loop_guided_next (long *istart, long *iend);

	bool GOMP_loop_runtime_next (long *istart, long *iend);

	bool GOMP_loop_ordered_static_next (long *istart, long *iend);

	bool GOMP_loop_ordered_dynamic_next (long *istart, long *iend);

	bool GOMP_loop_ordered_guided_next (long *istart, long *iend);

	bool GOMP_loop_ordered_runtime_next (long *istart, long *iend);


	void GOMP_parallel_loop_static_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size);

	void GOMP_parallel_loop_dynamic_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr, long chunk_size);

	void GOMP_parallel_loop_guided_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size);

	void GOMP_parallel_loop_runtime_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr);

	void GOMP_parallel_loop_static (void (*fn) (void *), void *data,
			   unsigned num_threads, long start, long end,
			   long incr, long chunk_size, unsigned flags);

	void GOMP_parallel_loop_dynamic (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, long chunk_size, unsigned flags);


	void GOMP_parallel_loop_guided (void (*fn) (void *), void *data,
			  unsigned num_threads, long start, long end,
			  long incr, long chunk_size, unsigned flags);
	
	void GOMP_parallel_loop_runtime (void (*fn) (void *), void *data,
			    unsigned num_threads, long start, long end,
			    long incr, unsigned flags);
	
	void GOMP_loop_end (void);
	void GOMP_loop_end_nowait (void);
	bool GOMP_loop_end_cancel (void);

	/* loop_ull.c */

	bool GOMP_loop_ull_static_start (bool up, unsigned long long start, unsigned long long end,
			    unsigned long long incr, unsigned long long chunk_size,
			    unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_dynamic_start (bool up, unsigned long long start, unsigned long long end,
			     unsigned long long incr, unsigned long long chunk_size,
			     unsigned long long *istart, unsigned long long *iend);


	bool GOMP_loop_ull_guided_start (bool up, unsigned long long start, unsigned long long end,
			    unsigned long long incr, unsigned long long chunk_size,
			    unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_runtime_start (bool up, unsigned long long start, unsigned long long end,
			     unsigned long long incr, unsigned long long *istart, unsigned long long *iend);


	bool GOMP_loop_ull_ordered_static_start (bool up, unsigned long long start, unsigned long long end,
				    unsigned long long incr, unsigned long long chunk_size,
				    unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_ordered_dynamic_start (bool up, unsigned long long start, unsigned long long end,
				     unsigned long long incr, unsigned long long chunk_size,
				     unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_ordered_guided_start (bool up, unsigned long long start, unsigned long long end,
				    unsigned long long incr, unsigned long long chunk_size,
				    unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_ordered_runtime_start (bool up, unsigned long long start, unsigned long long end,
				     unsigned long long incr, unsigned long long *istart,
				     unsigned long long *iend);

	bool GOMP_loop_ull_static_next (unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_dynamic_next (unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_guided_next (unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_runtime_next (unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_ordered_static_next (unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_ordered_dynamic_next (unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_ordered_guided_next (unsigned long long *istart, unsigned long long *iend);

	bool GOMP_loop_ull_ordered_runtime_next (unsigned long long *istart, unsigned long long *iend);

	/* ordered.c */

	void GOMP_ordered_start (void);
	void GOMP_ordered_end (void);

	/* parallel.c */

	void GOMP_parallel_start (void (*fn) (void *), void *data, unsigned num_threads);
	void GOMP_parallel_end (void);

	void GOMP_parallel (void (*fn) (void *), void *data, unsigned num_threads, unsigned int flags);
	bool GOMP_cancel (int which, bool do_cancel);
	bool GOMP_cancellation_point (int which);

	/* task.c */

	void GOMP_task (void (*fn) (void *), void *data, void (*cpyfn) (void *, void *),
	   long arg_size, long arg_align, bool if_clause, unsigned flags,
	   void **depend);

	void GOMP_taskwait (void);
	void GOMP_taskyield (void);
	void GOMP_taskgroup_start (void);
	void GOMP_taskgroup_end (void);

	/* sections.c */

	unsigned GOMP_sections_start (unsigned count);

	unsigned GOMP_sections_next (void);

	void GOMP_parallel_sections_start (void (*fn) (void *), void *data,
			      unsigned num_threads, unsigned count);

	void GOMP_parallel_sections (void (*fn) (void *), void *data,
			unsigned num_threads, unsigned count, unsigned flags);

	void GOMP_sections_end (void);
	
	void GOMP_sections_end_nowait (void);
	
	bool GOMP_sections_end_cancel (void);

	/* single.c */

	bool GOMP_single_start (void);

	void *GOMP_single_copy_start (void);

	void GOMP_single_copy_end (void *data);

	/* target.c */

	void GOMP_target (int device, void (*fn) (void *), const void *unused,
	     size_t mapnum, void **hostaddrs, size_t *sizes,
	     unsigned char *kinds);

	void GOMP_target_data (int device, const void *unused, size_t mapnum,
		  void **hostaddrs, size_t *sizes, unsigned char *kinds);

	void GOMP_target_end_data (void);

	void GOMP_target_update (int device, const void *unused, size_t mapnum,
		    void **hostaddrs, size_t *sizes, unsigned char *kinds);

	void GOMP_teams (unsigned int num_teams, unsigned int thread_limit);

#ifdef __cplusplus
}
#endif

#endif // hookomp_h__
