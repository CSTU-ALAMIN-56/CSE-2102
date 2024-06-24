//inserting first index
#include<stdio.h>
int insert_first(int a[],int n, int new_element)
{
    for(int i=n-1;i>=0;i--)
    {
        a[i+1] = a[i];
    }
    a[0] = new_element;

    return n+1;
}
int main()
{
    int n,new_element;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Write a new element to add first index of array: ");
    scanf("%d",&new_element);

    n = insert_first(a,n,new_element);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
