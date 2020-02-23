/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
using namespace std;
#define ln '\n'


#define PI acos(-1)
#define ll long long int
#define ull unsigned long long

/// ************************************** Code starts here ****************************************** */



const int maxn = 1e7 + 10;
bool Isprime[maxn];
int prime[maxn/10];
int totalPrime = 0;

void sv()
{

    int t = sqrt(maxn);
    for( int i=3; i<=t; i += 2 )
    {
        if( !Isprime[i] )
        {
            for( int j=i*i; j<maxn; j+= i+i)
                Isprime[j] = true;
        }
    }
    totalPrime = 0;
    prime[totalPrime++] = 2;
    for(int i=3; i<maxn; i+=2)
        if( !Isprime[i] )
            prime[totalPrime++] = i;
}



int main()
{
    //  freopen("in.txt","r",stdin);
    sv();
    int tt;
    ll n ;
    scanf("%d",&tt);
    for(int i=1;i<=tt;i++)
    {
    scanf("%lld",&n);
    ll ans = 1;
    for( int j=0; j<totalPrime && prime[j]*prime[j]<=n; j++ )
    {
        if(n%prime[j]==0)
        {
            int counT = 0 ;
            while( n % prime[j] == 0 )
            {
                n /= prime[j] ;
                counT++ ;
            }
            ans = ans * (2*counT+1);
        }
    }
    if( n>1 )
        ans *= (2*1+1);
    ans = ans/2 + 1; /// for pair (n,n)

    printf("Case %d: %lld\n",i,ans);
    }



    /// Comment the debugger section
}

