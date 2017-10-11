
#ifndef PREPOSTDEF_H
#define PREPOSTDEF_H

#define PREPOSTDEF 1	

#ifdef __cplusplus 
extern "C" {
#endif

	/* parallel.c */

	void PRE_GOMP_parallel_start (void);
	void PRE_GOMP_parallel_end (void);

	void POST_GOMP_parallel_start (void);
	void POST_GOMP_parallel_end (void);

	void PRE_GOMP_loop_dynamic_start(void);
	void POST_GOMP_loop_dynamic_start(void);

	void PRE_GOMP_loop_dynamic_next(void);
	void POST_GOMP_loop_dynamic_next(long, long);

	/* task */
	void PRE_GOMP_task(void);
	void POST_GOMP_task(void);

#ifdef __cplusplus
}
#endif


#endif /* PREPOSTDEF_H */
