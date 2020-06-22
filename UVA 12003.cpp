///*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*///

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define sf scanf
#define pf printf

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

#define fastio ios_base::sync_with_stdio(false)

///Inline functions

inline bool EQ(double a, double b)
{
    return fabs(a-b) < 1e-9;
}
//inline bool isLeapYearll year) { return (year%400==0) | (year%4==0 && year%100!=0); }
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
inline ll modSub(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
inline ll modPow(ll b, ll p)
{
    ll r = 1;
    while(p)
    {
        if(p&1)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}
inline ll modInverse(ll a)
{
    return modPow(a, MOD-2);
}
inline ll modDiv(ll a, ll b)
{
    return modMul(a, modInverse(b));
}
inline bool isInside(pii p,ll n,ll m)
{
    return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m);
}
inline bool isInside(pii p,ll n)
{
    return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n);
}
inline bool isSquare(ll x)
{
    ll s = sqrt(x);
    return (s*s==x);
}
inline bool isFib(ll x)
{
    return isSquare(5*x*x+4)|| isSquare(5*x*x-4);
}
inline bool isPowerOfTwo(ll x)
{
    return ((1ll<<(ll)log2(x))==x);
}


/// DEBUG --------------------------------------------------------------------------------->>>>>>

///**
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p )
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v )
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin() )
            os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v )
{
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v )
{
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin() )
            os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu ()
{
    cerr << endl;
}

template <typename T>
void faltu( T a[], int n )
{
    for (int i = 0; i < n; ++i)
        cerr << a[i] << ' ';
    cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}

/// TEMPLATE ----------------------------------------------------------------------->>>>>>


struct func
{
//this is a sample overloading function for sorting stl
    bool operator()(pii const &a, pii const &b)
    {
        if(a.F==b.F)
            return (a.S<b.S);
        return (a.F<b.F);
    }
};
/*------------------------------Graph Moves----------------------------*/
//Rotation: S -> E -> N -> W
//const int fx[] = {0, +1, 0, -1};
//const int fy[] = {-1, 0, +1, 0};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

/// Bit Operations
/// count set bit C = (num * 0x200040008001Ull & 0x111111111111111Ull) % 0xf; /// 32 bit integer
/// inline bool checkBit(ll n, int i) { return n&(1ll<<i); }
/// inline ll setBit(ll n, int i) { return n|(1ll<<i); }
/// inline ll resetBit(ll n, int i) { return n&(~(1ll<<i)); }


/// ************************************** Code starts here ****************************************** */

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int maxn = 565;

struct Block
{
    int size;
    ll a[maxn];
    void make_order()
    {
        sort(a+1,a+size+1);
    }
    void change(ll last,ll key) /// erase first !! not positional modifying
    {
        int pos = lower_bound(a+1,a+size+1,last) - a;
        a[pos] = key;
        while(pos>1 && a[pos-1] > a[pos])
            swap(a[pos-1],a[pos]),pos--;
        while(pos<size && a[pos] > a[pos+1])
            swap(a[pos],a[pos+1]),pos++;
    }
    int rank(ll key)
    {
        return lower_bound(a+1,a+size+1,key)-a-1;
    }
    void print()
    {
        for(int i=1; i<=size; i++)
            printf("%lld\n",a[i]);
    }
} block[maxn];
int maxblock,cap;
inline int idx(int pos)
{
    return (pos-1)/cap+1;
}
ll arr[maxn*maxn];
int n,m;
ll u;
void init()
{
    scanf("%d%d%lld",&n,&m,&u);
    cap = floor(sqrt(n+0.1));
    maxblock=1;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",arr+i);
        block[maxblock].a[++block[maxblock].size] = arr[i];
        if(block[maxblock].size == cap)
            maxblock++;
    }
    if(!block[maxblock].size)
        maxblock--;
    for(int i=1; i<=maxblock; i++)
        block[i].make_order();
}
int query(int l,int r,ll key)
{
    int ret = 0;
    if(idx(l) == idx(r))
    {
        for(int i=l; i<=r; i++)
            ret += arr[i]<key;
        return ret;
    }
    for(int i=l; i<=idx(l)*cap; i++)
        ret += arr[i]<key;
    for(int i=(idx(r)-1)*cap+1; i<=r; i++)
        ret += arr[i]<key;
    for(int i=idx(l)+1; i<=idx(r)-1; i++)
        ret += block[i].rank(key);
    return ret;
}
void modify(int pos,ll key)
{
    int id = idx(pos);
    block[id].change(arr[pos],key);
    arr[pos] = key;
}
int main()
{

    init();
    for(int i=1; i<=m; i++)
    {
        int l,r,p;
        ll v;
        scanf(" %d %d %lld %d",&l,&r,&v,&p);
        int k = query(l,r,v);
        modify(p,u*k/(r-l+1));
    }
    for(int i=1; i<=n; i++)
        printf("%lld\n",arr[i]);
    return 0;
}


/// greater than a number or less than a number in a range
