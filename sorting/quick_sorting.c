//quicksort algorithm in c
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int  partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<=j)
    {
        while(arr[i]<=pivot)
        i++;
        while(arr[j]>pivot)
        j--;
        if(i<=j)
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[j],&arr[low]);
    return j;

}

void quicksort(int arr[],int low,int high)
{
    int index;
    if(low<high)
    {
        index=partition(arr,low,high);
        quicksort(arr,low,index-1);
        quicksort(arr,index+1,high);
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
    int arr[]={1,3,5,6,2,4,9,7,3,6,0,1,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printer(arr,n);
    quicksort(arr,0,n-1);
    printer(arr,n);
    return 0;
}