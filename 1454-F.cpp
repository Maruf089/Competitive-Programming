/// Credit bi11a1 (Sir)


///*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*///

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define No              cout<<"No\n"
#define Yes             cout<<"Yes\n"
#define no              cout<<"no\n"
#define yes             cout<<"yes\n"
#define NO              cout<<"NO\n"
#define YES             cout<<"YES\n"

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define MOD 1000000007
#define PI acos(-1)
#define ll long long
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

#define fastio  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
///Inline functions

inline bool EQ(double a, double b)
{
    return fabs(a-b) < 1e-9;
}
//inline bool isLeapYell year) { return (year%400==0) | (year%4==0 && year%100!=0); }
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
    return ((1LL<<(ll)log2(x))==x);
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

/// inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
/// inline ll setBit(ll n, int i) { return n|(1LL<<i); }
/// inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }


/// ************************************** Code starts here ****************************************** */

/*
// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;

// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।
*/



const int MX=2e5+5;
const int INF=2e9;

int ara[MX];
pair<int,int> tree[4*MX];

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]= {ara[b], ara[b]};
        return;
    }
    int lft=2*node, rht=lft+1, mid=(b+e)/2;
    build(lft, b, mid);
    build(rht, mid+1, e);
    tree[node].first=max(tree[lft].first, tree[rht].first);
    tree[node].second=min(tree[lft].second, tree[rht].second);
}

pair<int,int> query(int node, int b, int e, int l, int r)
{
    if(b>r || e<l)
        return {0, INF};
    if(b>=l && e<=r)
        return tree[node];
    int lft=2*node, rht=lft+1, mid=(b+e)/2;
    pair<int,int> p1, p2;
    p1=query(lft, b, mid, l, r);
    p2=query(rht, mid+1, e, l, r);
    return {max(p1.first, p2.first), min(p1.second, p2.second)};
}

int main()
{
    fastio;

    int i, j, k;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(i=0; i<n; ++i)
            cin >> ara[i];
        build(1, 0, n-1);
        int mx=0, low, high, mid, ans;
        pair<int,int> p;
        for(i=0; i<n; ++i)
        {
            mx=max(mx, ara[i]);

            //lft-mx
            low=i+2, high=n-1, ans=-1;
            while(high>=low)
            {
                mid=(low+high)/2;
                p=query(1, 0, n-1, mid, n-1);
                if(p.first==mx)
                {
                    ans=mid;
                    high=mid-1;
                }
                else if((p.first<mx))
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            if(ans==-1)
                continue;
            int lft=ans;

            //rht-mx
            low=lft, high=n-1, ans=-1;
            while(high>=low)
            {
                mid=(low+high)/2;
                p=query(1, 0, n-1, mid, n-1);
                if(p.first==mx)
                {
                    ans=mid;
                    low=mid+1;
                }
                else if((p.first<mx))
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            if(ans==-1)
                continue;
            int rht=ans;

            //middle-min
            low=lft-1, high=rht-1, ans=-1;
            while(high>=low)
            {
                mid=(low+high)/2;
                p=query(1, 0, n-1, i+1, mid);
                if(p.second==mx)
                {
                    ans=mid;
                    break;
                }
                else if((p.second<mx))
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            if(ans==-1)
                continue;
            cout << "YES" << endl;
            cout << i+1 << " " << ans-i << " " << n-ans-1 << endl;
            break;
        }
        if(i==n)
            puts("NO");
    }
}
