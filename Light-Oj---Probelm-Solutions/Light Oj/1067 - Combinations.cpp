#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000003

//ll bigmod( ll n,ll p)
//{
//
//if( p == 1 )
//    return n;
//
//if( p%2 == 0 )
//    return ( bigmod(n,p/2) * bigmod(n,p/2) )% m ;
//else
//    return ( n * bigmod(n,p-1) ) %m;
//}
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


 ll* a = new ll[1000003];
 ll x,y,t,n,k,i,j;
 a[0] = 1 ;

for( j=1; j<=1000001; j++)
    a[j] = ( a[j-1]*j ) % m ;

cin>>n;

for(i=1; i<=n; i++)
{
    cin>>x>>y;

    ll res =( a[y] * (a[x-y] ) ) % m ;
    res = ( a[x] * bigmod( res, m-2 ) ) % m ;

    printf("Case %lld: %lld\n",i,res);

}
delete[] a;
}
