#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,S;
    cin>>n;
    int a[n],b[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
