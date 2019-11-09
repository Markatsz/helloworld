#include "sort.h"

static inline int partition(void *p, int n, cmp_f cmp, swap_f swap)
{
    int pos = 0;
    int i = 0;
    int j = n -1;

    while (i < j)
    {
        for (;i<j;j--)
            if (cmp(p, pos, j) > 0)
            {
                swap(p, j, pos);
                pos = j;
                break;
            }

        for (;i<j;i++)
            if (cmp(p, i, pos) > 0)
            {
                swap(p ,i, pos);
                pos = i;
                break;
            }
    }

    return pos;
}

int quickSort(void *p, int n, cmp_f cmp, swap_f swap, off_f off)
{
    int idx = 0;
    if (n < 2) return 0;

    idx = partition(p, n, cmp, swap);

    quickSort(p, idx, cmp, swap, off);
    quickSort(off(p, idx + 1), n-1-idx, cmp, swap, off);

    return 0;
}
