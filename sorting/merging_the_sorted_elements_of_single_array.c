//merging the sorted elements of single array
#include<stdio.h>
void merge(int a[],int mid,int low,int high)
{
    int i,j,k;
    int b[high+1];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
        b[k]=a[i];
        k++;
        i++;
        }
        else{
        b[k]=a[j];
        k++;
        j++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<high+1;i++)
    {
        a[i]=b[i];
    }
    for(i=0;i<high+1;i++)
    {
        printf("%d ",a[i]);
    }

}

int main()
{
    int a[]={5,6,7,1,2,3};
    int n=sizeof(a)/sizeof(a[0]);
    int mid=2;
    merge(a,mid,0,n-1);
}