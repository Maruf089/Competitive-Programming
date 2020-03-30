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

#define fastio ios_base::sync_with_stdio(false)

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

const int MAX = 1e6 + 5;
const ll inf = 1e18 + 5;

int arr[MAX];
struct state
{
    int len, link;
    map<char, int> next;
};
state st[MAX];
int id, last;
string s;
ll ans[MAX];
void init()
{
    for(int i=0; i<=id; i++)
    {
        st[i].len = 0;
        st[i].link = 0;
        st[i].next.clear();
        ans[i] = 0;
    }
    st[1].len = -1;
    st[1].link = 1;
    st[2].len = 0;
    st[2].link = 1;
    id = 2;
    last = 2;
}

void extend(int pos)
{
    while(s[pos - st[last].len - 1] != s[pos])
        last = st[last].link;
    int newlink = st[last].link;
    char c = s[pos];
    while(s[pos - st[newlink].len - 1] != s[pos])
        newlink = st[newlink].link;
    if(!st[last].next.count(c))
    {
        st[last].next[c] = ++id;
        st[id].len = st[last].len + 2;
        st[id].link = (st[id].len == 1 ? 2 : st[newlink].next[c]);
        ans[id] += ans[st[id].link];
    }
    last = st[last].next[c];
}

int main()
{

    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        string temp = a;
        reverse(temp.begin(), temp.end());
        int n = a.size();
        if(a == temp)
        {
            cout<<a<<"\n";
            continue;
        }

        s = a;
        string ans = "";
        init();
        for(int i=0; i<s.size(); i++)
        {
            extend(i);
        }
        if(st[last].len > (int)ans.size())
            ans = s.substr(s.size() - st[last].len,s.size());
//dbg(ans,st[last].len);

        init();
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++)
            extend(i);
        if(st[last].len > (int)ans.size())
            ans = s.substr(s.size() - st[last].len,s.size());
// dbg(ans,st[last].len);

        int i = 0, j = a.size()-1;
        int len = 0;
        while(i < j)
        {
            if(a[i] != a[j])
                break;
            i++;
            j--;
        }

        len = i;
        init();
        s = "";
        for(int l=i; l<=j; l++)
        {
            s += a[l];
        }
// dbg(s);
        for(int l=0; l<s.size(); l++)
            extend(l);
        if(len*2 + st[last].len > ans.size())
            ans = a.substr(0,len) + a.substr(n-len-st[last].len, n);
// dbg(ans);
        init();
        reverse(s.begin(), s.end());
        for(int l=0; l<s.size(); l++)
            extend(l);
        if(len*2 + st[last].len > ans.size())
            ans = a.substr(0,len + st[last].len) + a.substr(n-len,n);

        cout<<ans<<"\n";
    }

}
