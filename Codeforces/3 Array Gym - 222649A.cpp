/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f(a,b) for(int i=a;i<=(b);i++)
#define TC int tt;scanf("%d",&tt);for(int t=1;t<=tt;t++)
#define _case      printf("Case %d: ",z)

#define MOD 1000000007
#define countv(v,a) count(v.begin(),v.end(),a)
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define uniq(v) v.resize( unique(all(v)) - v.begin())

#define PI acos(-1)
#define ll long long int
#define ull unsigned long long
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define sz size()
#define GCD(a,b) __gcd(a,b)
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
// order_of_key(x) – ফাংশনটি x এলিমਠƨ্টট`ƕোন পজিশনে আছে সেটা বলে দেয়।

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

/**
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

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;
const int mx = (int)1e5+9;
/// count set bit C = (num * 0x200040008001ULL & 0x111111111111111ULL) % 0xf; /// 32 bit integer

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
/// inline int msb(ll x) { union { double a; int b[2]; }; a = x;return (b[1] >> 20) - 1023;}
/// inline int rightmostbitposition(ll x) { return x&(-x);}
struct Point
{
    ll s,p,x,y;
    string name;
    /// Point() {}
    ///  Point(double x,double y) : x(x), y(y) {}
    bool operator < (const Point &ob)const /// decreasing sort as same as compare function
    {
        return s==ob.s ? p<ob.p : s>ob.s;
    }
};

double distance(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
/// ************************************** Code starts here ****************************************** */
string s,s1;
ll n,m,a,b,i,j,d,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
vector<pll>vc;
map<ll,ll>mp;

/*
int main()
{
  //  freopen("in.txt","r",stdin);
  fast;

 ll ta,tb,tc;
 inp2(d,ta);
 inp2(tb,tc);


  f0(i,ta)
  {
      inp(a);
      vc.pb({a,0});
  }
  f0(i,tb)
  {
      inp(a);
      vc.pb({a,1});
  }
  f0(i,tc)
  {
     inp(a);
      vc.pb({a,2});
  }
  sort(all(vc));

 // dbg(vc);

  for(i=0,j=0;i<vc.sz;i++)
  {

   // dbg(vc[i]);
      for(;j<vc.sz;j++)
      {
          if(vc[j].F-vc[i].F>d)
            break;
  //  dbg(vc[j]);
          mp[vc[j].S]++;
      }
 //       dbg(mp[0],mp[1],mp[2]);
        ans += mp[0]*mp[1]*mp[2];
  //      dbg(vc[i].S,mp[vc[i].S],ans);
        mp[vc[i].S]--;
        ans -= mp[0]*mp[1]*mp[2];
 //   dbg(ans);
  }
 printf("%lld\n",ans);



  /// Comment the debugger section
}


*/

vector<ll>vca,vcb,vcc;
int main()
{
    fast ;
    ll ta,tb,tc;
    cin >> d >> ta >> tb >> tc;
    f0(i,ta)
    {
        cin >> a ;
        vca.pb(a);
    }
    f0(i,tb)
    {
        cin >> a ;
        vcb.pb(a);
    }
    f0(i,tc)
    {
        cin >> a ;
        vcc.pb(a);
    }

    for(i=j=k=0; i<ta&&j<tb&&k<tc;)
    {
        if(vca[i]<=vcb[j] and vca[i]<=vcc[k])
        {
           a = upper_bound(all(vcb),vca[i]+d)-vcb.begin()-j;
           b = upper_bound(all(vcc),vca[i]+d)-vcc.begin()-k;
           ans += a*b;
           i++;
        }
        else if(vcb[j]<=vca[i] and vcb[j]<=vcc[k])
        {
           a = upper_bound(all(vca),vcb[j]+d)-vca.begin()-i;
           b = upper_bound(all(vcc),vcb[j]+d)-vcc.begin()-k;
           ans += a*b;
           j++;
        }

        else
        {
           a = upper_bound(all(vcb),vcc[k]+d)-vcb.begin()-j;
           b = upper_bound(all(vca),vcc[k]+d)-vca.begin()-i;
           ans += a*b;
           k++;
        }
    }
    cout << ans << ln ;
}
