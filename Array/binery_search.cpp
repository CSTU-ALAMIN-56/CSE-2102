#include<iostream>
using namespace std;
bin_search(int a[], int low, int high, int value)
{
    bool p=false;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(a[mid]==value)
        {cout<<"Finding value index is: "<<mid<<endl;
           p=true;
            break;
        }
        else if(a[mid]<value)
        {
            low = mid+1;
        }
        else high = mid-1;
    }
    if(!p) cout<<"The value is not found"<<endl;
}
int main()
{
    int a[7] = {1,4,8,60,65,70,75};

    int n;
    cin>>n;

    bin_search(a,0,6,n);

}
