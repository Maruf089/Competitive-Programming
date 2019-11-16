#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int a,b,n,k,i,j,c=0,s=0,m;

    cin>>n>>k;
    int x[n+1],z[n+1],sum[n+1];

    for(i=1;i<=n;i++)
    cin>>x[i];

    sum[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>z[i];
        if(z[i]==1)
        {
            s += x[i];
            x[i] = 0;
        }
        sum[i] = sum[i-1]+x[i];
    }
    ///cout<<s<<endl;
    int maxx=0;
    for(i=1;i-1+k<=n;i++)
    {
            maxx=max(maxx,abs(sum[i-1]-sum[i-1+k]));
    }
    cout<<s+maxx;

}
