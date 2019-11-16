#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,t=0,Max,Min,p=0,d=0,c=0;

    cin>>n;
    int a[n];

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    Max=a[0];
    Min=a[0];

    for(i=0; i<n; i++)
    {
        if(a[i]>Max)
        {
            Max=a[i];
            d=i;
        }

        if(a[i]<=Min)
        {
            Min=a[i];
            p=i;
        }

    }

    if(d>p)
        t=1;

        cout<<d-t+n-1-p;
}
