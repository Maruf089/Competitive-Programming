///*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*///

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%d",&x)
#define inp2(a,b) scanf("%d %d",&a,&b)
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
const int maxs = 200005;


int mark[505][35];
int a[maxs];
int ans[maxs];
int sz,bl,n;


void update_block(int bl,int x){
	int i;
	for(i=0;i<32;i++){
		if((x&(1<<i))==0 && mark[bl][i]==0){
			ans[bl]=INT_MAX;
			for(int j=bl*sz;j<min(n,(bl+1)*sz);j++){
				a[j]=a[j]&x;
				ans[bl]=min(ans[bl],a[j]);
			}
			mark[bl][i]=1;
		}
	}
}

void update(int l,int r,int x)
{
    int sbl=l/sz;
    int ebl=r/sz,i;
    if(sbl==ebl)
    {
        for(i=l; i<=r; i++)
            a[i] = a[i]&x;

        ans[sbl] = INT_MAX; /// for finding minimum
        for(i=sbl*sz; i<min((sbl+1)*sz,n); i++)
            ans[sbl] = min(ans[sbl],a[i]);
    }
    else
    {
        for(i=l; i<min(n,(sbl+1)*sz); i++)
            a[i]=a[i]&x;

        ans[sbl]= INT_MAX;  /// left block er kaj purota sesh
        for(i=sbl*sz; i<min((sbl+1)*sz,n); i++)
            ans[sbl]=min(ans[sbl],a[i]);

        for(i=ebl*sz; i<=r; i++)
            a[i]=a[i]&x;

        ans[ebl]= INT_MAX; /// right block er kaj purota sesh
        for(i=ebl*sz; i<min((ebl+1)*sz,n); i++)
            ans[ebl]=min(ans[ebl],a[i]);

        for(int i=sbl+1; i<ebl; i++)
            update_block(i,x);

    }
}

int query(int l,int r)
{
    int ret=INT_MAX;
    int sbl=l/sz;
    int ebl=r/sz,i;
    if(sbl==ebl)
    {
        for(i=l; i<=r; i++)
        {
            ret=min(ret,a[i]);
        }
    }
    else
    {
        for(i=l; i<min(n,(sbl+1)*sz); i++)
        {
            ret=min(ret,a[i]);
        }
        for(i=ebl*sz; i<=r; i++)
        {
            ret=min(ret,a[i]);
        }
        for(i=sbl+1; i<ebl; i++)
        {
            ret=min(ret,ans[i]);
        }
    }
    return ret;
}

int main()
{
    //  freopen("in.txt","r",stdin);
    int q,i,j,type,l,r,x;
    inp2(n,q);

    f0(i,n)
    {
        inp(a[i]);
    }
    sz = sqrt(n);
    bl = -1 ;

    f0(i,maxs)
    ans[i] = INT_MAX;

    for(i=0; i<n; i++)
    {
        if(i%sz==0)
            bl++;
        ans[bl] = min(a[i],ans[bl]);
    }

    for(i=0; i<bl; i++)
        for(j=0; j<32; j++)
            mark[i][j] = 0;

    for(i=0; i<q; i++)
    {
        inp(type);
        inp2(l,r);
        l--,r--;
        if(type==0)
        {
            int ans = query(l,r);
            pf("%d\n",ans);
        }
        else
        {
            inp(x);
            update(l,r,x);
        }
    }




    /// Comment the debugger section
}
