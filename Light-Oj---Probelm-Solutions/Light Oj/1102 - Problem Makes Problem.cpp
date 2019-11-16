#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll m = 1000000007;
ll a[2000000];

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

    ll x,k,t,n,i,j,ans;
    a[0] = 1 ;

    for( j=1; j<=2000000; j++)
        a[j] = ( a[j-1]*j ) % m ;

    cin>>t;

    for(i=1; i<=t; i++)
    {
        cin>>n>>k;

        ll down =( a[n] * a[k-1] ) % m ;

        ans = ( a[n+k-1] * bigmod( down, m-2 ) ) % m ;

        cout<<"Case "<<i<<": "<<ans<<endl;

    }

}

