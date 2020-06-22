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

#define fo(i,b) for(int i=0;i<(b);i++)
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

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;
const int mx = (int)1e5+9;

const int N=400011,M=100011;
int BLOCK;

struct node
{
    int l, r, i, sp, ans;
} Q[M];

int lvl[N], P[N][20],T[N], st[N], en[N], id[2*N], occ[N], ans, w[N];
map<int, int> HASH;
int cnt[N];
vector<int> g[N];
int i,j,ti;


bool cmp(node a, node b)
{
    if (a.l/BLOCK != b.l/BLOCK)
        return a.l < b.l;
    return a.r < b.r;
}

bool gg(node a, node b){
	return a.i < b.i;
}

void dfs(int u, int p)
{

    st[u] = ++ti;
    id[ti] = u;
    T[u] = p ;
    for(auto v: g[u])
    {
        if (v == p)
            continue;
        lvl[v] = lvl[u]+1;
        dfs(v, u);
    }
    en[u] = ++ti;
    id[ti] = u;
}

void LCA_INIT(int N)
{
    MEM(P,-1);
    for (i = 1; i <= N; i++)
        P[i][0] = T[i];

    for (j = 1; j <= 20; j++)
        for (i = 1; i <= N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int LCA_QUERY(int N, int p, int q) /// N = total node number
{
    int tmp, log, i;

    if (lvl[p] < lvl[q])  /// swap
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>lvl[p])
            break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (lvl[p] - (1 << i) >= lvl[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}


void add(int node){
	occ[node]++;
	cnt[w[node]]++;
	if (occ[node] == 2){
		cnt[w[node]] -= 2;
		if (cnt[w[node]] == 0)
			ans--;
	}
	else if (cnt[w[node]] == 1) ans++;
}
void del(int node){
	int wt = w[node];
	occ[node]--;

	if (occ[node] == 1){
		cnt[wt]++;
		if (cnt[wt] == 1)
			ans++;
		return;
	}
	cnt[wt]--;
	if (cnt[wt] == 0) ans--;
}
int main() {
   //  freopen("in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n, m, i, j, u, v;
	ans = ti = 0;
	cin>>n>>m;
	BLOCK = sqrt(n);
	int no = 0;
	HASH.clear();
	fo(i, n){
		cin>>w[i+1];
		if (HASH.find(w[i+1]) == HASH.end())
			HASH[w[i+1]] = ++no;
		w[i+1] = HASH[w[i+1]];

	}
	fo(i, n-1){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	lvl[1] = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(occ, 0, sizeof(occ));

	dfs(1, 0);

	LCA_INIT(n);

	fo(i, m){
		Q[i].i = i;
		Q[i].sp = -1;
		cin>>u>>v;
		if (lvl[u] < lvl[v])
			swap(u, v);
		int w = LCA_QUERY(n,u, v);
		if (w == v){
			Q[i].l = st[v];
			Q[i].r = st[u]+1;
		}else{
			if (st[v] > en[u]){
				Q[i].l = en[u];
				Q[i].r = st[v]+1;
			}
			else{
				Q[i].l = en[v];
				Q[i].r = st[u]+1;
			}
			// Special case: We have to consider 'w' separately.
			Q[i].sp = w;
		}
	}
	sort(Q, Q+m, cmp);
	int currL = 0, currR = 0, L, R;
	fo(i, m){
		L = Q[i].l, R = Q[i].r;
		while (currL < L){

			del(id[currL]);
			currL++;
		}
		while (currL > L){
			add(id[currL-1]);
			currL--;
		}
		while (currR < R){
			add(id[currR]);
			currR++;
		}
		while (currR > R){
			del(id[currR-1]);
			currR--;
		}
		Q[i].ans = ans;
		if (Q[i].sp != -1){
			if (cnt[w[Q[i].sp]] == 0)
				Q[i].ans = ans+1;
		}
	}
	sort(Q, Q+m, gg);
	fo(i, m)
		cout<<Q[i].ans<<endl;

	return 0;
}
