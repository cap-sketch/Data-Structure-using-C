//linear search
#include<stdio.h>
int main()
{
    int n;
    printf("total elements: ");
    scanf("%d",&n);
    int a[n];
    printf("enter elements of the array: ");
    for(int j=0;j<n;j++)
    {
        scanf("%d",&a[j]);
    }
    int item;
    printf("the element to be searched: ");
    scanf("%d",&item);
    int loc=-1;
    int i=0;
    while(i<n && a[i]!=item)
    {
        i=i+1;
    }
    if(a[i]==item)
    printf("the element is found at %d location",i+1);
    else
    printf("the element is not found");
    return 0;
}