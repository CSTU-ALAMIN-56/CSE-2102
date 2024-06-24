//search an array element
#include<stdio.h>
search(int a[], int n, int item)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==item) return i;
    }
}
int main()
{
    int a[5];
    for(int i=0;i<5;i++)
    scanf("%d",&a[i]);

    int element;
    printf("Write finding element\n");
    scanf("%d",&element);
    int index = search(a,5,element);
    printf("Searching element index is %d ",index);
}
