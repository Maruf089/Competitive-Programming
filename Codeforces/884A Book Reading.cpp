#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i,j,r,s=0;
    cin>>n>>t;
    int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=86400-a[i];
        if(s>=t)
        {
            cout<<i+1;
            return 0;
        }
    }
}
