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

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
//inline bool isLeapYearll year) { return (year%400==0) | (year%4==0 && year%100!=0); }
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
const int fx[] = {0, +1, 0, -1};
const int fy[] = {-1, 0, +1, 0};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/


ll n,m,a,b,t,i,j,d,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
vector<pair<ll,ll>>vc;
map<ll,ll>mp;

int dir_x[4]= {-1, 1, 0, 0};
int dir_y[4] = {0, 0, -1, 1};
int visited[55][55];
char arr[55][55];

int BFS(int x,int y,int good)
{
    MEM(visited,0);
    queue<pair<ll,ll>>Q;
    Q.push({x,y});
    visited[x][y] = 1;

    int flag = 0 ;
    while(!Q.empty())
    {
        pair<ll,ll> node = Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int xx = node.F + dir_x[i];
            int yy = node.S + dir_y[i];

                if((xx>=0 && xx<n) && (yy>=0 && yy<m) && arr[xx][yy]!='#' && arr[xx][yy]!='B' && visited[xx][yy]==0)
                {
                    visited[xx][yy] = 1;
                    if(arr[xx][yy]=='G')
                        good--;
                    Q.push({xx, yy});
                }
        }
    }
    return good ;
}



int main()
{

      t = 1 ;
      cin >> t ;
      while(t--)
      {
          cin >> n >> m ;
          ll good = 0 , bad = 0 ;
          vc.clear();

          f0(i,n)
          {
              f0(j,m)
              {
                  cin >> arr[i][j];
                  if(arr[i][j]=='B')
                        bad++;
                  else if(arr[i][j]=='G')
                        good++;
              }
          }
          if(good==0)
          {
              cout << "yes\n";
              continue;
          }

          int flag =  0 ;

          f0(i,n)
          {
              f0(j,m)
              {
                  if(arr[i][j]=='B')
                  {
                      for(int k=0;k<4;k++)
                      {
                          int xx = i+fx[k];
                          int yy = j+fy[k];

                           if((xx>=0 && xx<n) && (yy>=0 && yy<m) )
                           {
                               if(arr[xx][yy]=='.')
                               {
                                   arr[xx][yy] = '#' ;
                               }
                               else if(arr[xx][yy]=='G')
                               {
                                   flag = 1 ;
                                   break;
                               }
                           }
                      }
                  }
              }
          }

          if(flag)
          {
              cout << "no\n";
              continue;
          }
          if(arr[n-1][m-1]=='.')
          good = BFS(n-1,m-1,good);

          if(good==0)
              cout << "yes\n";
          else
              cout << "no\n";

      }

}
