
#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 1
#define VERBOSE 1

#if defined(DEBUG) && DEBUG > 0
 #define TRACE(fmt, args...)	do{ fprintf(stderr, "DEBUG: [%10s:%07d] in %s(): " fmt, \
    __FILE__, __LINE__, __func__, ##args); } while(0)
#else
 #define TRACE(fmt, args...) do{ } while (0)
#endif

// #define VERBOSE 1
// Use make OPTIONS=-DVERBOSE
#if defined(VERBOSE) && VERBOSE > 0
#define PRINT_FUNC_NAME fprintf(stderr, "TRACE: [%10s:%07d] Calling [%s()]\n", __FILE__,__LINE__, __FUNCTION__)
#else
#define PRINT_FUNC_NAME (void) 0
#endif

#endif /* DEBUG_H */
