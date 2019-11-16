#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i,c=0,s=5,d=0;

    cin>>n>>k;
    int a[n];

    k=240-k;

    for(i=1; i<=n; i++)
    {
        d=d+s*i;
        c++;

        if(d==k)
        {
            cout<<c;
            return 0;
        }
        if(d>k)
        {
            cout<<c-1;
            return 0;
        }

    }
    cout<<c;
}
