//inserting last index
#include<stdio.h>
int insert(int a[],int n,int new_element)
{
    a[n] = new_element;
    return n+1;
}
int main()
{
    int n,new_element;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Write a new element to add last index of array: ");
    scanf("%d",&new_element);

    n = insert(a,n,new_element);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
