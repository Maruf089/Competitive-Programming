#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[10001],rem[10001];
ll gcd, x, y;
void extended_Euclid(ll A, ll B)
{
    if(B == 0)
    {
        gcd = A;
        x = 1;
        y = 0;
    }
    else
    {
        extended_Euclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }

}

ll inverse(ll a, ll m)
{
    extended_Euclid(a,m);
    x = x % m;
     if( x < 0) x += m;

    return x;
}

ll findMinX(ll num[], ll rem[], ll k)
{
    ll product = 1,i,j;

    for (i = 0; i < k; i++)
        product *= num[i];

    ll result = 0;

    for (i = 0; i < k; i++)
    {
        ll M = product / num[i];
        result += rem[i] * inverse(M, num[i]) * M;
    }

    return (result % product);
}

int main()
{
    ll i,t,n,temp,a,m,c=0;
    cin>>t;

    while(t--)
    {
    cin>>n;
    for( i = 0 ; i < n ; i++ )
    {
    cin>>num[i]>>rem[i];
    }
    cout << "Case "<<++c<<": "<<findMinX(num, rem, n)<<endl;
    }

}

