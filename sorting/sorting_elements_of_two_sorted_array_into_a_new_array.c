//sorting elements of two sorted array into a new array
#include<stdio.h>
void merge(int a[],int b[],int c[],int m,int n)
{
    int i,j,k;
    i=j=k=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
        c[k]=a[i];
        i++;k++;
        }
        else
        {
            c[k]=b[j];
            j++;k++;
        }
        
    }
    while(i<m)
        {
            c[k]=a[i];
            k++;i++;
        }
        while(j<n)
        {
            c[k]=b[j];
            k++;
            j++;
        }
}
int main()
{
    int a[]={1,3,5,7,9};
    int m=sizeof(a)/sizeof(a[0]);
    int b[]={2,4,6,8};
    int n=sizeof(b)/sizeof(b[0]);
    int c[50];
    merge(a,b,c,m,n);
    for(int i=0;i<m+n;i++)
    {
        printf("%d ",c[i]);
    }
}