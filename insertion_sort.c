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

void insertionSort(int *a, int n)
{
    int i;
    int j;
    int piv;

   i = 1;
   while (i < n)
   {
       piv = a[i];
       j = i - 1;
       while (j >= 0 && a[j] > piv)
       {
           a[j + 1] = a[j];
           j--;
       }
       a[j + 1] = piv;
       i++;
   }
}

int main(void)
{
    int a[10] = {10, 1, 2, 9, 3, 6, 5, 7, 8, 4};
    insertionSort(a, 10);
    for (int i = 0; i < 10; i++)
        printf("%d\n",a[i]);
    return (0);
}
