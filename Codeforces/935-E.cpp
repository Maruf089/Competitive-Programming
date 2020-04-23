///*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*///

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
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

const int N = 11111;
const int M = 10010;
const int inf = 1e9 + 7;
int mx[101][M];
int mn[101][M];
int match[N];
int sign[N];
string s;
int n;
vector<int> graph[M];
int node;
int val[M];
int Plus, Minus;

int create(int l, int r)
{
    if (l == r)
    {
        val[++node] = s[l] - '0';
        return node;
    }

    int p = create(l + 1, sign[l] - 1);
    int q = create(sign[l] + 1, r - 1);
    int t = ++node;
    graph[t].push_back(p);
    graph[t].push_back(q);
    return t;
}

void MAX(int &x, int y)
{
    if (x < y)
        x = y;
}

void MIN(int &x, int y)
{
    if (x > y)
        x = y;
}

void dfs(int x)
{
    if (graph[x].empty())
    {
        mx[0][x] = val[x];
        mn[0][x] = val[x];
        for (int i = 1; i <= Plus; i++)
        {
            mx[i][x] = -inf;
            mn[i][x] = inf;
        }
        return;
    }
    for (auto it : graph[x])
        dfs(it);

    int p = graph[x][0];
    int q = graph[x][1];

    for (int i = 0; i <= Plus; i++)
    {
        mx[i][x] = -inf;
        mn[i][x] = inf;

        for (int j = 0; j <= i; j++)
        {
            MAX(mx[i][x], mx[j][p] - mn[i - j][q]);
            MIN(mn[i][x], mn[j][p] - mx[i - j][q]);
        }
        for (int j = 0; j < i; j++)
        {
            MAX(mx[i][x], mx[j][p] + mx[i - j - 1][q]);
            MIN(mn[i][x], mn[j][p] + mn[i - j - 1][q]);
        }
    }
}

void rev(int x)
{
    if (graph[x].empty())
    {
        mx[0][x] = val[x];
        mn[0][x] = val[x];
        for (int i = 1; i <= Minus; i++)
        {
            mx[i][x] = -inf;
            mn[i][x] = inf;
        }
        return;
    }
    for (auto it : graph[x])
        rev(it);

    int p = graph[x][0];
    int q = graph[x][1];

    for (int i = 0; i <= Minus; i++)
    {
        mx[i][x] = -inf;
        mn[i][x] = inf;
        for (int j = 0; j < i; j++)
        {
            MAX(mx[i][x], mx[j][p] - mn[i - j - 1][q]);
            MIN(mn[i][x], mn[j][p] - mx[i - j - 1][q]);
        }
        for (int j = 0; j <= i; j++)
        {
            MAX(mx[i][x], mx[j][p] + mx[i - j][q]);
            MIN(mn[i][x], mn[j][p] + mn[i - j][q]);
        }

    }
}


int main()
{

    cin >> s;
    cin >> Plus >> Minus;
    stack<pair<int, char>> st;
    int n = s.size();
    memset(val, -1, sizeof val);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push({i, '('});
        }
        else if (s[i] == '?')
        {
            st.push({i, '?'});
        }
        else if (s[i] == ')')
        {
            int p = st.top().first;
            st.pop();
            int q = st.top().first;
            st.pop();
            match[q] = i;
            sign[q] = p;
        }
    }

    create(0, n - 1);
    if (Plus <= Minus)
    {
        dfs(node);
        cout << mx[Plus][node] << "\n";
    }
    else
    {
        rev(node);
        cout << mx[Minus][node] << "\n";
    }
    return 0;
}

