//binery search
#include<stdio.h>
void bin(int a[],int lb,int ub, int item)
{
    int c=0;
    while(lb<=ub)
    {
        int mid = (lb+ub)/2;
        if(a[mid]==item)
        {
            printf("The index of finding value is %d ",mid);
            c=1;
            break;
        }
        else if(a[mid]<item)  lb=mid+1;
        else ub=mid-1;
    }
    if(c==0) printf("The value is not found\n");
}
int main()
{
    int n,element;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

    printf("Write finding value\n");
    scanf("%d",&element);
    bin(a,0,n,element);
}
