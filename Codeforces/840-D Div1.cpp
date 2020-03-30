
/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%lld",&x)
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

#define fast ios_base::sync_with_stdio(false)

/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */

//using namespace __gnu_pbds;
/*
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমࡆɠǍটটޠকোন পজিশনে আছে সেটা বলে দেয়।

*/

///Inline functions

inline bool EQ(double a, double b)
{
    return fabs(a-b) < 1e-9;
}
inline bool isLeapYear(ll year)
{
    return (year%400==0) | (year%4==0 && year%100!=0);
}
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
/// count set bit C = (num * 0x200040008001ULL & 0x111111111111111ULL) % 0xf; /// 32 bit integer
/// inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
/// inline ll setBit(ll n, int i) { return n|(1LL<<i); }
/// inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }


/// ************************************** Code starts here ****************************************** */

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;
const int mx = (int)3e5+9;
int flag = 0 ;
ll n,m,a,b,t,i,j,qq,d,q,cs=0,counT=0,k,ans=0,num;
ll K = 10 ;
vector<ll>vc,result;
vector<pll>tree[4*mx];
map<ll,ll>mp,mp1;

void comp(pll &a,pll &b)
{
    a.S == b.S ? a.F<b.F : a.S>b.S ;
}
void merge(const vector<pll>&l,const vector<pll>&r,vector<pll>&ans)
{
    int i=0,j=0;
    ans.reserve(10);
//dbg(l,r,ans);
    while(i<l.sz or j<r.sz)
    {
        if(i==l.sz)
            ans.pb(r[j++]);
        else if(j==r.sz)
            ans.pb(l[i++]);
        else if(l[i].F<r[j].F)
            ans.pb(l[i++]);
        else if(l[i].F>r[j].F)
            ans.pb(r[j++]);
        else ans.pb({l[i].F,l[i].S+r[i].S}),i++,j++;
    }
    sort(ans.begin(), ans.end(), [](pll a,pll b) {return a.second == b.second ? a.first < b.first : a.second > b.second;});
    while(ans.sz>K)
        ans.pop_back();
    sort(all(ans));

}
void build(ll lo, ll hi, ll node)
{
    if(lo == hi)
    {
        tree[node].pb({vc[lo],1});
    }
    else{
    ll mid = (lo + hi) / 2;
    build(lo, mid, node << 1);
    build(mid + 1, hi, node<<1 | 1);

    merge(tree[node<<1],tree[node<<1 | 1],tree[node]);
    }
}


void query(ll lo, ll hi, ll l, ll r,int low_occur,ll node)
{
    if(lo > r || hi < l)
        return ;
    else if(lo >= l && hi <= r)
    {
        for(auto it : tree[node])
        {
           if(mp1[it.F]!=qq)
           mp1[it.F] = qq , mp[it.S] = 0 , result.pb(it.F);

            mp[it.F] += it.S;
        }
    }
    else{
    ll mid = lo+hi >> 1;
    query(lo, mid, l, r, low_occur, node<<1) ;
    query(mid + 1, hi, l, r, low_occur, node<<1 | 1);
    }
}


int main()
{
    //fast ;
    //  freopen("in.txt","r",stdin);
    scanf("%lld %lld",&n,&q);
    vc.pb(0) ; /// for 1 indexing
    f0(i,n)
    {
        scanf("%lld",&a);
        vc.pb(a);
    }
    build(1,n,1);

    f1(i,q)
    {
        ll l,r;
        scanf("%lld %lld %lld",&l,&r,&k);
        flag = 0 ;
        qq = i;
        int low_occur = (r-l+1)/k;
        query(1,n,l,r,low_occur,1);

        ll res = INF ;
        for(auto it : result)
        {
            if(mp[it]>low_occur)
                res = min(res,it);
        }
        if(res!=INF)
        printf("%lld\n",res);
        else printf("-1\n");
        //     cout << ans << ln ;
        result.clear();
    }


    /// Comment the debugger section
}


