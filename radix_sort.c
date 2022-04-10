#include <stdio.h>
#include <stdlib.h>

int get_max(int *a, int n)
{
    int max;
    int i;

    max = a[0];
    i = 0;
    while (i < n)
    {
        if (a[i] > max)
            max = a[i];
        i++;
    }
    return (max);
}

void countSort(int *a, int n, int index)
{
    int *b;
    int *cont;
    int i;
    int max;

    i = 0;
    max = (a[0] / index) % 10;
    i = 0;
    while (i < n)
    {
        if (((a[i] / index) % 10) > max)
            max = a[i];
        i++;
    }
    i = 0;
    b = calloc(n, sizeof(int));
    cont = calloc(max, sizeof(int));
    while (i < n)
    {
        cont[(a[i] / index) % 10]++;
        i++;
    }
    i = 1;
    while (i <= n)
    {
        cont[i] += cont[i - 1];
        i++;
    }
    i = n - 1;
    while (i >= 0)
    {
        b[cont[(a[i] / index) % 10] - 1] = a[i];
        cont[(a[i] / index) % 10]--;
        i--;
    }
    i = 0;;
    while (i < n)
    {
        a[i] = b[i];
        i++;
    }
    free(b);
}

void radixSort(int *a, int n)
{
    int max;
    int index;

    max = get_max(a, n);
    index = 1;
    while (max / index > 0)
    {
        countSort(a, n, index);
        index *= 10;
    }
}

int main(void)
{
    int a[100] = {2, 30, 2, 2, 3, 6, 5, 7, 8, 4, 42, 8, 4, 15, 20, 32, 99, 64, 20, 30, 50 , 10};
    radixSort(a, 22);
    for (int i = 0; i < 22; i++)
        printf("%d\n",a[i]);
    return (0);
}
