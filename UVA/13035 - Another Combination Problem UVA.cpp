/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define pf printf
#define sf scanf
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)

#define D(x) cerr<< #x " = "<<x<<endl
#define dbg(x) cerr << #x << " = " << x << endl;
#define D2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f(a,b) for(int i=a;i<=(b);i++)
#define test_case(t)    for(int z=1;z<=t;z++)
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
#define vi vector <int>
#define vll vector <ll>
#define vs vector <string>
#define pb push_back
#define eb emplace_back
#define mpii map <int,int>
#define mpsi map <string,int>
#define mpll map <long long,long long>
#define MP make_pair
#define F first
#define S second
#define sz size()
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b)))
//#define harmonic(n) 0.57721566490153286l+log(n)

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())

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
*/

///Inline functions

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) | (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline bool isInside(pii p,ll n,ll m){ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); }
inline bool isInside(pii p,ll n){ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); }
inline bool isSquare(ll x){ ll s = sqrt(x);    return (s*s==x); }
inline bool isFib(ll x) { return isSquare(5*x*x+4)|| isSquare(5*x*x-4); }
inline bool isPowerOfTwo(ll x){ return ((1LL<<(ll)log2(x))==x); }


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

struct Point{
    ll s,p,x,y;
    string name;
   /// Point() {}
  ///  Point(double x,double y) : x(x), y(y) {}
bool operator < (const Point &ob)const /// decreasing sort as same as compare function
    {
        return s==ob.s ? p<ob.p : s>ob.s;
    }
};

double distance(Point a , Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
/// ************************************** Code starts here ****************************************** */
string s,s1;
ll n,m,a,b,i,j,d,t,c,cs=0,counT=0,k,ans=0,l=0,sum1=0,Max,Min,num;
vector<ll>vc;
map<ll,ll>mp;

int main()
{

  cin >> t ;
  test_case(t)
  {
      cin >> n ;
      a = n ;
      b = n+1;
      c = n+2;
      bool two=false,three=false,flag=false;
      if(a%2==0 or a%3==0 and flag==false)
      {
          if(a%3==0)
          {
              a/=3;
              three=true;
            //  flag = true;
          }
          if(a%2==0)
          {
              a/=2;
              two=true;
            //  flag = true;
          }
      }
      if(b%3==0 and three==false)
      {
          b/=3;three=true;
      }
      if(b%2==0 and two==false)
      {
          b/=2;two=true;
      }
      if(c%3==0 and three==false)
      {
          c/=3;three=true;
      }
      if(c%2==0 and two==false)
      {
          c/=2;two=true;
      }

      ull sum = (((a*b)%MOD)*c)%MOD;
      ull ans = (sum*2)%MOD ;
      _case;
      cout << ans << ln ;
  }

}


/// Another

//#include <bits/stdc++.h>
//using namespace std;
//
//const long long MOD = 1000000007;
//void exgcd(long long x, long long y, long long &g,
//		long long &a, long long &b) {
//	if (y == 0)
//		g = x, a = 1, b = 0;
//	else
//		exgcd(y, x%y, g, b, a), b -= (x/y) * a;
//}
//long long inverse(long long x, long long p) {
//	long long g, b, r;
//	exgcd(x, p, g, r, b);
//	if (g < 0)	r = -r;
//	return (r%p + p)%p;
//}
//int main() {
//	int testcase, cases = 0;
//	scanf("%d", &testcase);
//	while (testcase--) {
//		long long n;
//		scanf("%lld", &n);
//		n++;
//		long long ret = 1;
//		ret = (n+1)*(n)%MOD*(n-1)%MOD;
//		ret = ret * inverse(2, MOD)%MOD * inverse(3, MOD)%MOD;
//		ret = ret * 2 %MOD;
//		printf("Case %d: %lld\n", ++cases, ret);
//	}
//	return 0;
//}
