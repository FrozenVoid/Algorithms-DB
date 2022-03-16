Djbsort is a fast integer sort
that uses a branchless minmax swap.
https://sorting.cr.yp.to/

code:
https://sorting.cr.yp.to/djbsort-20190516/h-internal/int32_minmax.c.html

#define int32_MINMAX(a,b) \
do { \
  int32 ab = b ^ a; \
  int32 c = b - a; \
  c ^= ab & (c ^ b); \
  c >>= 31; \
  c &= ab; \
  a ^= c; \
  b ^= c; \
} while(0)
