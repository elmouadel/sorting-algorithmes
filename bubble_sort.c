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

void bubbleSort(int *a, int n)
{
    int i;
    int j;

    i = n - 1;
    while (i)
    {
        j = 0;
        while (j < i)
        {
            if (a[j] > a[j + 1])
                swap(&a[j + 1], &a[j]);
            j++;
        }
        i--;
    }
}

int main(void)
{
    int a[10] = {1, 10, 2, 9, 3, 6, 5, 7, 8, 4};
    bubbleSort(a, 10);
    for (int i = 0; i < 10; i++)
        printf("%d\n",a[i]);
    return (0);
}
