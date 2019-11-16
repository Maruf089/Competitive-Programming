#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k,i,j,s=0,c=0;
    cin>>n>>k;
    long a[200005];

    for( i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    if(k==0)
    {
        if(a[0]==1)
            cout<<"-1";
        else
            cout<<"1";
        return 0;
    }
    if(k==n||a[k-1]!=a[k])
        cout<<a[k-1]<<endl;
    else
        cout<<"-1";

}

