//merge sorting
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

}
void ms(int a[],int l,int h)
{
    if(l<h)
    {
         int mid=(l+h)/2;
        ms(a,l,mid);
        ms(a,mid+1,h);
        merge(a,mid,l,h);
    }
}
void printer(int a[],int n)
{
for(int i=0;i<n;i++)
{
    printf("%d ",a[i]);
}
}

int main()
{
    int a[]={5,8,7,4,2,6};
    int n=sizeof(a)/sizeof(a[0]);
    ms(a,0,n-1);
    printer(a,n);
}