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

int const N = 1000001;
int divisors[N];
bool sol[N];
vector<int> res;

int main()
{
    for(int i = 1; i < N; ++i)
        for(int j = i; j < N; j += i)
            ++divisors[j];

    memset(sol, true, sizeof sol);
    for(int i = 1; i < N; ++i)
        for(int j = i; j < N; j += i)
            if(divisors[j] <= 3 || divisors[j] % divisors[i] != 0)
                sol[j] = false;

    for(int i = 1; i < N; ++i)
        if(sol[i])
            res.push_back(i);

    for(int i = 107; i < (int)res.size(); i += 108)
        printf("%d\n", res[i]);

}

