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

void selectionSort(int a[], int n) 
{
    int i;
    int j;
    int max;

    i = n - 1;
    while (i > 0)
    {
        j = 0;
        max = i;
        while (j < i)
        {
            if (a[j] > a[max])
                max = j;
            j++;
        }
        swap(&a[i], &a[max]);
        i--;
    }
}

int main(void)
{
    int a[10] = {1, 10, 2, 9, 3, 6, 5, 7, 8, 4};
    selectionSort(a, 10);
    for (int i = 0; i < 10; i++)
        printf("%d\n",a[i]);
    return (0);
}
