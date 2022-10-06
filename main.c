#include <stdio.h>
#include <stdlib.h>
int count;
void quicksort(int number[100], int first, int last);

int main()
{
   int i, n, number[100];

   printf("Enter number of elements: ");
   scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("Enter element number %d \n",i+1);
        scanf("%d", &number[i]);}

   quicksort(number, 0, n - 1);

   printf("Elements after Sorting ");
   for (i = 0; i < n; i++)
      printf(" %d", number[i]);

   printf("\nNumber of Comparisons:%d", count);

   return 0;
}

void quicksort(int number[100], int first, int last)
{
   int i, j, pivot, temp;

   if (first < last)
   {
      pivot = first;
      i = first;
      j = last;

      while (i < j)
      {
         count++;
         while (number[i] <= number[pivot] && i < last)
            i++;
         count++;
         while (number[j] > number[pivot])
            j--;
         if (i < j)
         {
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         }
      }

      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;
      quicksort(number, first, j - 1);
      quicksort(number, j + 1, last);
   }
}
