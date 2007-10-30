/* Various utility functions.
 *
 * Most of these functions are defined in the libc. However, pulling
 * the libc in is quite a big hit on kernel size in some cases.
 */

#include "mytypes.h"
#include "util.h"

void memcpy(U8 *dest, const U8 *src, U32 len) {
  while (len--) {
    *dest++ = *src++;
  }
}

void memset(U8 *dest, const U8 val, U32 len) {
  while (len--) {
    *dest++ = val;
  }
}

U32 strlen(const char *str) {
  U32 i = 0;

  while (*str++)
    i++;

  return i;
}

U8 strncmp(const char *a, const char *b, U32 n) {
  U8 i;
  
  for (i=0 ; i<n ; i++) {
    if (a[i] < b[i]) {
      return -1;
    } else if (a[i] > b[i]) {
      return 1;
    }
  }
  
  return 0;
}

U8 strcmp(const char *a, const char *b) {
  return strncmp(a, b, MIN(strlen(a), strlen(b)));
}
