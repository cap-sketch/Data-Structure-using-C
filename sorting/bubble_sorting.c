//buble sorting 
#include<stdio.h>

void swap(int *a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)               //pass loop
    {
        for(int j=0;j<n-1-i;j++)           //comparison loop
        {
            if(a[j]>a[j+1])
            {
            swap(&a[j],&a[j+1]);
            }
        }
    }
}
void printer(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int a[]={1,3,5,9,2,4,7};
    int n=sizeof(a)/sizeof(a[0]);
    printer(a,n);
    bubblesort(a,n);
    printer(a,n);

}