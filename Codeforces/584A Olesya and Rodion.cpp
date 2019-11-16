#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,t,i,sum=0;
    cin>>n>>t;

    if(n==1 && t==10)
    {
        cout<<"-1";
        return 0;
    }

    if(t==10)
    {
        for(i=1; i<=n; i++)
        {
            if(i==n)
            {
                cout<<"0";
                return 0;
            }
            else
                cout<<"1";
        }
        return 0;
    }
    for(i=1; i<=n; i++)
    {
        cout<<t;
    }
}

