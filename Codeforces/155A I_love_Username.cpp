#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,c=0,Max,Min;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        if(i==0)
        {
            Max=a[i];
            Min=a[i];
        }
        if(a[i]>Max)
        {
            Max=a[i];
            c++;
        }
        if(a[i]<Min)
        {
            Min=a[i];
            c++;
        }
    }
    cout<<c;

}
