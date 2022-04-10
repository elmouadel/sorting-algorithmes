#include <stdio.h>
#include <stdlib.h>

void countSort(int *a, int n)
{
    int *b;
    int *cont;
    int max;;
    int i;

    b = calloc(n, sizeof(int));
    max = a[0];
    i = 0;
    while (i < n)
    {
        if (a[i] > max)
            max = a[i];
        i++;
    }
    i = 0;
    cont = calloc((max + 1), sizeof(int));
    while (i < n)
    {

        cont[a[i]]++;
        i++;
    }
    i = 1;
    while (i <= max)
    {
        cont[i] += cont[i - 1];
        i++;
    }
    i = 0;
    while (i < n)
    {

        b[cont[a[i]] - 1] = a[i];
        cont[a[i]]--;
        i++;
    }
    i = 0;
    while (i < n)
    {
        a[i] = b[i];
        i++;
    }
    free(b);
}

int main(void)
{
    int a[100] = {2, 10, 2, 2, 3, 6, 5, 7, 8, 4, 3, 8, 4, 1, 2, 5, 6, 4, 2, 3, 0 , 2};
    countSort(a, 22);
    for (int i = 0; i < 22; i++)
        printf("%d\n",a[i]);
    return (0);
}
