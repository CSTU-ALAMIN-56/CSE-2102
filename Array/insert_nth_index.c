//inserting nth index
#include<stdio.h>
int insert(int a[],int n,int k,int new_element)
{
    for(int i=n-1;i>=k;i--)
    {
        a[i+1] = a[i];
    }
    a[k] = new_element;

    return n+1;
}
int main()
{
    int n,new_element,k;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Write index and element: ");
    scanf("%d%d",&k,&new_element);

    n = insert(a,n,k,new_element);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
