/**
 *
 * Created by Sharukh Hasan on 8/09/16.
 * Copyright © 2016 HyperCryptic Solutions, LLC. All rights reserved.
 *
 */

#ifndef YAMALLOC_H_
#define YAMALLOC_H_

#include <stdlib.h>
#include <stddef.h>
//#include <malloc.h>

#ifdef __cplusplus
extern "C" {
#endif

extern __attribute__((constructor)) void yam_init();
extern __attribute__((destructor)) void yam_exit();
extern void yam_free(void* chunk);
extern void* yam_malloc(size_t sz);
extern void* yam_realloc(void* chunk, size_t sz);
extern void* yam_calloc(size_t sz, size_t cnt);
extern void* yam_memalign(size_t alignment, size_t sz);
extern size_t yam_malloc_size(void* ptr);

#ifdef __YAM_MALLOC
#define malloc               yam_malloc
#define realloc              yam_realloc
#define free                 yam_free
#define calloc               yam_calloc
#define memalign             yam_memalign
#endif


#ifdef __cplusplus
}
#endif


#endif /* YAMALLOC_H_ */
