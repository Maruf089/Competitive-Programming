#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main()
{
    int n,i,a,b,j,ans=0,m;
    int static sum=0;
    cin>>n;

        cin>>a>>b;
        sum=abs(a-b);
        ans=sum;
        m=sum;

        for(i=1;i<n;i++)
        {
            cin>>a>>b;
            if(ans>m)
            {
                m=ans;
            }
            ans=abs(ans-a)+b;
        }
        if(ans>m)
        cout<<ans;
        else
            cout<<m;
}
