#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,ans=0;
    cin>>n;
    for(i=1;i<=n/2;i++)
    {
        if(n%i==0)
            ans++;
    }
    cout<<ans;
}

