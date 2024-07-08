//selection sorting
//time complexity-o(n^2);
//space complexity-o(1);
#include<stdio.h>
void swap(int *a ,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int arr[],int n)
{
   for(int i=0;i<n-1;i++)
   {
    int min_index=i;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]<arr[min_index])
        {
            min_index=j;
          
        }
        
    }
      if(min_index!=i)
        {
            swap(&arr[i],&arr[min_index]);
        }
   }

}
void printer(int arr[],int n)
{
   for(int i=0;i<n;i++)
   {
    printf("%d ",arr[i]);
   }
   printf("\n");
}
int main()
{
    int arr[]={2,4,6,8,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    printer(arr,n);
    selection_sort(arr,n);
    printer(arr,n);
    return 0;
}