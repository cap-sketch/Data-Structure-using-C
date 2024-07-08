//bubble sorting adaptive method
#include<stdio.h>

void swap(int *a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int a[],int n)
{
    int issorted;
    for(int i=0;i<n-1;i++)
    {
        issorted=1;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
            swap(&a[j],&a[j+1]);
            issorted=0;
            }
            if(issorted)
            return ;
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
   // int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    printer(a,n);
    bubblesort(a,n);
    printer(a,n);

}