#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,s=0,c=0;
    cin>>n;
    int a[n+1];

    for( i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if(n==2)
    {
        cout<<a[0];
        return 0;
    }
    if(n%2!=0)
    cout<<a[n/2];
    else
        cout<<a[n/2-1];
}
