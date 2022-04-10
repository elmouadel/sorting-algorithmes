#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int mi, int m, int ma)
{
    int o[130];
    int li;
    int ri;
    int i;
    int hol;

    i = mi;
    hol = ma;
    li = mi;
    ri = m + 1;
    while (li <= m && ri <= ma)
    {
        if (a[ri] < a[li])
        {
            o[i] = a[ri];
            ri++;
        }
        else
        {
            o[i] = a[li];
            li++;
        }
        i++;
    }
    while (li <= m)
    {
        o[i] = a[li];
        li++;
        i++;
    }
    while (ri <= ma)
    {
        o[i] = a[ri];
        ri++;
        i++;
    }
    i = mi;
    while (i <= ma)
    {
        a[i] = o[i];
        i++;
    }  
}

void mergeSort(int *a, int mi, int ma)
{
    int m;
    m = (ma + mi) / 2;
    if (mi < ma)
    {
        mergeSort(a, mi, m);
        mergeSort(a, m + 1, ma);
        merge(a, mi, m, ma);
    }
}

int main(void)
{
    int a[100] = {2, 7, 3, 6, 4, 10, 11, 1, 8, 20, 15, 18, 41, 30, 17, 14, 13, 24, 12, 0};
    mergeSort(a, 0, 19);
    for (int i = 0; i < 20; i++)
        printf("%d\n",a[i]);
    return (0);
}
