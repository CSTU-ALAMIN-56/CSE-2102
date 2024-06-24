#include<stdio.h>
int del_kth_element(int a[], int k,int n)
{
    for(int i=k-1;i<n;i++)
    {
        a[i] =a[i+1];
    }
    return n-1;
}
int main ()
{
    printf("Write index of array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    int del;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Which element do you want to delete? ");
    scanf("%d",&del);

     n= del_kth_element(a,del,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
