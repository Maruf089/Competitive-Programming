#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int

///Inline functions
inline void normal(ll &a)
{
    a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a*b)%MOD;
}
inline ll modAdd(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a+b)%MOD;
}

ll n,m,a,b,t,i,j,k,ans,num;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5)   // returns true if n is probably prime, else returns false.
{
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++)
    {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

int main()
{

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n&1)
        {
            if(MillerRabin(n))
                    ans = modMul(n,1LL);
            else
            {
                double SQRT = pow(n,0.5);
                ll SQRT1 = SQRT;
                if(SQRT1==SQRT)
                {
                    k = SQRT1;
                    ans = modMul(n,k);
                }
                else
                {
                    for(i=3;;i+=2)
                    {
                        if(n%i==0)
                        {
                            k = max(i,n/i);
                            ans = modMul(n,k);
                            break;
                        }
                    }
                }
            }
        }
        else
            ans = modMul(n,n/2);

        printf("%lld\n",ans);
    }
}
