//delating last index
#include<stdio.h>
int delete_last(int n)
{
    return n-1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    n = delete_last(n);
    printf("New array:\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);

}

