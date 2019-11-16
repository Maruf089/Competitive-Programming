#include<bits/stdc++.h>
#define endl '\n'
#define sf scanf
#define sfi(a) sf("%d",&a)
#define sfl(a) sf("%lld",&a)
#define sff(a,b) sf("%d %d",&a,&b)
#define sffl(a,b) sf("%lld %lld",&a,&b)
#define sfff(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c) sf("%lld %lld %lld",&a,&b,&c)
#define pf printf
#define pfi(a) pf("%d\n",a)
#define pfl(a) pf("%lld\n",a)
#define pffi(a,b) pf("%d %d\n",a,b)
#define pffl(a,b) pf("%lld %lld\n",a,b)
#define _case cout<<"Case "<<++cs<<": "
#define FOR(I,N) for(i=0;i<n;i++)
#define FORa(i,a,n) for(i=1;i<=n;i++)

#define PI acos(-1)
#define ll long long int
#define ull unsigned long long

#define rev(v) reverse(v.begin(),v.end())
#define sort(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define srt(v) sort(v.begin(),v.end())

#define vi vector <int>
#define vs vector <string>
#define PB push_back
#define mpii map <int,int>
#define mpsi map <int,int>
#define mpll map <long long,long long>
#define MP make_pair
#define F first
#define S second

#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b)))
#define MEM(a, b) memset(a, b, sizeof(a))


#define INF 100000000
#define M 10000000007
#define countv(v,a) count(v.begin(),v.end(),a)
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define uniq(v) v.resize( unique(all(v)) - v.begin())

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout)

ll n,i,j,counT=0,k,l=0,m=0,temp=0,a,b;
string s;
const int MOD = 1e9+9;

ll ext_euclid(ll a, ll b, ll c, ll d)
{
    if(c == 0)
        return b;
    return
    ext_euclid(c,d,a%c,b-a/c*d);
}

ll inverse(ll x)
{
    return (ext_euclid(MOD,0,x,1)%MOD+MOD)%MOD;
}
ll Bigmod(ll x, ll p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return x;
    return Bigmod(x*x%MOD,p/2)*Bigmod(x,p%2)%MOD;
}

int main()
{
    cin >> n >> a >> b >> k >> s;
    int times = (n+1)/k;
    ll ans = 0;

    for(i=0;i<k;i++)
    {
        ll sign = (s[i]=='+'?1:-1);
        ///	Q = b^k*(a^-1)^k
        ///	Z = b^(i+k)*a^(n-i-k)
        ll R = Bigmod(b,k)*Bigmod(inverse(a),k)%MOD;
        ll A = Bigmod(b,i)*Bigmod(a,n-i)%MOD;
        /// cout << A << ' ' << R << '\n';
        ll cur;
        if(R != 1)
            cur = sign*A*(Bigmod(R,times)-1)%MOD*inverse(R-1)%MOD;
        else
            cur = sign * times *A % MOD;

        ans = (ans+cur)%MOD;
    }
    cout << (ans%MOD+MOD)%MOD << '\n';
}
