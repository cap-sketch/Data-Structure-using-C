//insertion sort
#include<stdio.h>
void insert(int a[],int n)
{
  //loop for passes
  for(int i=0;i<=n-1;i++)
  {
     int key=a[i];
     int j=i-1;
     //loop  for comparison
     while(a[j]>key && j>=0)
     {
        a[j+1]=a[j];
        j--;
     }
     a[j+1]=key;
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
    int a[]={1,3,5,7,9,2,4,6,0};
    int n=sizeof(a)/sizeof(a[0]);
    printer(a,n);
    insert(a,n);
    printer(a,n);
    return 1;
}