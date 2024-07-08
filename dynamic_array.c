#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct myarray
{
   int totalsize;
   int usedsize;
   int *ptr;
};

void createarray(struct myarray *a, int ts, int us)
{
   a->totalsize = ts;
   a->usedsize = us;
   a->ptr = (int *)malloc(ts * sizeof(int)); // Allocate memory for the array
}

void setvalue(struct myarray *a)
{
   printf("Enter elements:\n");
   for (int i = 0; i < a->usedsize; i++)
   {
      int n;
      scanf("%d", &n);
      (a->ptr)[i] = n;
   }
}

void display(struct myarray *a)
{
   printf("Array elements:\n");
   for (int i = 0; i < a->usedsize; i++)
   {
      printf("%d ", (a->ptr)[i]);
   }
   printf("\n");
}

int main()
{
   struct myarray arr;
   int totalsize, usedsize;

   printf("Enter total size of the array: ");
   scanf("%d", &totalsize);
   printf("Enter number of elements to be used: ");
   scanf("%d", &usedsize);

   createarray(&arr, totalsize, usedsize);
   setvalue(&arr);
   display(&arr);

   free(arr.ptr); // Free dynamically allocated memory
   return 0;
}
