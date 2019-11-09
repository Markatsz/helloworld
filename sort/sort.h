#ifndef SORT_H
#define SORT_H

typedef int (*cmp_f)(void*p, int i, int j);
typedef void (*swap_f)(void*p, int i, int j);
typedef void* (*off_f)(void*p, int i);

#endif