#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    if (*a == *b)
        return ;
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

int partition(int *a, int i, int j)
{
    int p;
    int m;
    int k;
    p = a[i];
    m = i;
    k = i + 1;
    while (k <= j)
    {
        if (a[k] < p)
        {
            m++;
            swap(&a[k], &a[m]);
        }
        k++;
    }
    swap(&a[i], &a[m]);
    return (m);
}

int    quickSort(int *a, int low, int high, int len)
{
    if (low < high)
    {
        int piv = partition(a, low, high);
        if (piv == len / 2)
        {
            len = a[piv];
            return (len);
        }

        quickSort(a, low, piv, len);
        quickSort(a, piv + 1, high, len);
    }
    return (len);
}

int main(void)
{
    int a[151] = {2, 7, 3, 6, 4, 10, 11, 1, 8, 20, 15, 18, 41, 30, 17, 14, 13, 24, 12, 0};
    printf("mid%d\n",quickSort(a, 0, 19, 20));
    for (int i = 0; i < 20; i++)
        printf("%d\n",a[i]);
    return (0);
}
