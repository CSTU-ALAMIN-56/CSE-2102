//delating first index
#include<stdio.h>

int delete_first(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        a[i-1] = a[i];
    }

    return n-1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    n = delete_first(a,n);
    printf("New array:\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);

    //n = delete_last(n);
}

