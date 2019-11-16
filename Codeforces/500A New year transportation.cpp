#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i,sum=0;
    cin>>n>>t;
    int a[n];
    for(i=0; i<n-1; i++)
    {
        cin>>a[i];
    }
    for  ( i=0; i<(n-1); )
    {
        i=i+a[i];
        if ( i==(t-1) )
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }

        cout<<"NO";
}
