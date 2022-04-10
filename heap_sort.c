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

void heapfy(int *a, int n)
{
    int i;
    int max;

    i = (n / 2) - 1;
    max = i;
    while(i >= 0)
    {
        if (a[i] < a[(2 * i) + 1])
        {
            max = (2 * i) + 1;
        }
        if (a[i] < a[(2 * i) + 2] && max < a[(2 * i) + 2])
        {
            max = (2 * i) + 2;
        }
        if (i != max)
        {
            swap (&a[i], &a[max]);
            i = (n / 2) - 1;
            max = i;
            continue ;
        }
        i--;
        max = i;
    }
}

void heapSort(int *a, int n)
{
    int i;

    i = n - 1;
    while (i > 1)
    {   
        heapfy(a, i);
        swap(&a[i], &a[0]);
        i--;
    }
}

int main(void)
{
    int a[100] = {30, -44, 4, 2, 99, 3, 6, 5, 7, 8, 4, 42, 8, 4, 15, 20, 32, 9, 64, 20, 30, 50 , 10};
    heapSort(a, 23);
    int c = 1;
    int cc = 1;
    int w = 100;

    //small visualization of the sorted heap
    for (int i = 0; i < 23; i++){
        if (c == cc)
        {
            printf("\n");
            printf("\n");
             w /= 2;
            cc *= 2;
        }
        c++;
        printf("%*d", w, a[i]);
        printf("%*s", w, "");
    }
    return (0);
}
