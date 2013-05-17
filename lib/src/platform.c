/*! \file platform.c
    \brief Wrap memory allocation routines so that we can use the matlab ones when we build for matlab.

    rwt_malloc, rwt_calloc, and rwt_free simply wrap the matlab or system versions of malloc, calloc, and free.
*/

#include "rwt_platform.h"

#ifdef MATLAB_MEX_FILE
  #include "matrix.h"
  void *rwt_malloc(size_t size) {
    return mxMalloc(size);
  }
  void *rwt_calloc(size_t num, size_t size) {
    return mxCalloc(num, size);
  }
  void rwt_free(void *ptr) {
    mxFree(ptr);
  }
#else
  void *rwt_malloc(size_t size) {
    return malloc(size);
  }
  void *rwt_calloc(size_t num, size_t size) {
    return calloc(num, size);
  }
  void rwt_free(void *ptr) {
    free(ptr);
  }
#endif
