#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007

ll bigmod( ll n,ll p)
{
    if( p == 0 )
        return 1;

    ll k = bigmod(n,p/2) ;
    k = (k*k) %m;

    if( p%2 == 1 )
    k = (n*k)%m ;

    return k;
}


int main()
{
    ll c=0,t,n,k,sum=0,i;
    cin>>t;
    while( t-- )
    {
        sum=0;
        cin>>n>>k;
        for(i=1; i<=n; i++)
        {
            sum += bigmod(k,__gcd(i,n));
            sum %= m;
        }
        cout<<"Case "<<(++c)<<": "<<(sum*bigmod(n,m-2))%m<<endl;
    }
}
