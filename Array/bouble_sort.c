#include<stdio.h>

void sort(int a[],int n)
{
    int i,j,c;

    for(int i=0;i<n-1;i++)
    {
        c=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;

                c=1;
            }
        }
        if(c == 0) break;
    }
}
int main ()
{
    int a[5] = {23,22,12,56,70};
    sort(a,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
