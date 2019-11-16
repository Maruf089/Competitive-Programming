/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
#define ln '\n'
#define sf scanf
#define pf printf

#define D(x) cout<< #x " = "<<x<<endl
#define cout(case)   cout << "Case " << ++cs << ": " ;
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)


#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))
#define _case cout<<"Case "<<++cs<<": "
#define lp(loop,start,end) for(ll loop=start;loop<=end;loop++)
#define lpd(loop,start,end) for(ll loop=end;loop>=start;loop--)



#define MOD 1000000007
#define countv(v,a) count(v.begin(),v.end(),a)
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define uniq(v) v.resize( unique(all(v)) - v.begin())


#define PI acos(-1)
#define ll long long int
#define ull unsigned long long

#define vi vector <int>
#define vll vector <ll>
#define vs vector <string>
#define pb push_back
#define mpii map <int,int>
#define mpsi map <string,int>
#define mpll map <long long,long long>
#define MP make_pair
#define F first
#define S second

#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b)))



#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())

#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))

#define fast ios_base::sync_with_stdio(false)
using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;
/// count set bit C = (num * 0x200040008001ULL & 0x111111111111111ULL) % 0xf; /// 32 bit integer

/*------------------------------Graph Moves----------------------------*/
//Rotation: S -> E -> N -> W
const int fx[] = {0, +1, 0, -1};
const int fy[] = {-1, 0, +1, 0};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

//Bit Operations
inline bool checkBit(ll n, int i)
{
    return n&(1LL<<i);
}
inline ll setBit(ll n, int i)
{
    return n|(1LL<<i);
}
inline ll resetBit(ll n, int i)
{
    return n&(~(1LL<<i));
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
inline ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}
inline ll lcm(ll a, ll b)
{
    return (a * (b / gcd(a, b)));
}

typedef struct
{
    double x,y;
} Point;

double distance(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}




ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,one=0,sum1=0,sum=0,Max,Min,num;
ll arr[10000000];
vector<pair<ll,ll> >vc;
map<ll,ll>mp;

int main()
{
    fast;
    cin >> n >> m ;
    ll arr[n+9][m+9],brr[n+9][m+9];;
    f1(i,n)
    {
        f1(j,m)
        {
            cin >> arr[i][j];
            if(arr[i][j])
                one++;
        }
    }


    if(one&1)
    {
        return cout << -1,0;
    }
    counT = 0 ;
    for(i=1; i<n; i++)
    {
counT = 0 ;
        for(j=1; j<m; j++)
        {
counT = 0 ;

            if(arr[i][j]==1 || arr[i][j]== -1 )
            {
                if(arr[i+1][j] == 1 || arr[i+1][j] == -1 ) // down
                    counT++;
                if(arr[i+1][j+1]==1 || arr[i+1][j+1]== -1) // down right corner
                    counT++;
                if(arr[i][j+1]==1 || arr[i][j+1]== -1) // right
                    counT++;

            }
            if(counT == 3 )
            {
                arr[i+1][j] = -1;
                arr[i][j] = -1;
                arr[i+1][j+1] = -1;
                arr[i][j+1]  = -1 ;

                counT = 0 ;
                vc.pb({i,j});


/// D(i);D(j);
     //           continue;
            }


/// D(counT);cout << i << " " << j << endl ;


        }

    }


     f1(a,n)
    {
        f1(b,m)
        {
            if(arr[a][b]==1)
            {
                return cout << -1,0;
            }

        }
     //   cout << endl;
    }
    if(vc.size()==0)
   cout << 0 ;
   else
   {
       cout << vc.size() << endl;
      for(i=0;i<vc.size();i++)
      {
          cout << vc[i].F << " " << vc[i].S << endl;
      }
   }
}
