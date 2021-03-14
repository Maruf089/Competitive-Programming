#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%lld",&x)
#define inps(x) scanf("%s",x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)


#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define MOD 1000000007
#define PI acos(-1)
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define F first
#define S second
#define sz size()
#define LCM(a,b) (a*(b/__gcd(a,b)))
//#define harmonic(n) 0.57721566490153286060651209+log(n)+1.0/(2*n)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))

#define fastio  ios_base::sync_with_stdio(false);
///Inline functions

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
//inline bool isLeapYll year) { return (year%400==0) | (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

const int mx = (int)1e5+9;

ll n,m,a,b,t,i,j;



#define NN 1000005
long total[1000005];
bool Isprime[NN];
int prime[NN + 9] , d[NN+9];
int totalPrime;

void sv()
{
    int t = sqrt(NN);
    Isprime[0]=Isprime[1]=1;

    for(int i = 4; i <= NN; i+= 2)
    Isprime[i] = 1;

    for( int i=3; i<=t; i += 2 )
    {
        if( !Isprime[i] )
        {
            for( int j=i*i; j<NN; j+= i+i)
                Isprime[j] = 1;
        }
    }
    totalPrime = 0;
    prime[totalPrime++] = 2;

    for(int i=3; i<NN; i+=2)
        if( !Isprime[i] )
            prime[totalPrime++] = i;
}

void CountDiv()
{
    for( int i=2;i<NN;i++ )
    {
        int N = i;
        int t = sqrt(N);
        int res = 1;
        for( int j=0;;j++ )
        {
            if( t<prime[j] ) break;
            int cnt = 1;
            while( N%prime[j]==0 )
            {
                N/=prime[j] ;
                cnt++;
            }
            t = sqrt(N);
            res*=cnt;
        }
        if( N>1 ) res*=2;
        d[i] = res;
    }
}

int main()
{
    sv();
    CountDiv();
    vector<ll>vc;

    for(i=1;i<=1000000;i++)
    {
        int sq = sqrt(d[i]);
        for(j=0;j<totalPrime;j++)
        {
            if(prime[j]>sq)break;
            if(d[i]%prime[j]==0)
            {
                if(not Isprime[d[i]/prime[j]] and prime[j]!=d[i]/prime[j])
                {
                    vc.pb(i);
                    break;
                }
            }
        }
    }
    for(i=9;i<vc.sz;i+=9)
        cout << vc[i-1] << ln;
}
