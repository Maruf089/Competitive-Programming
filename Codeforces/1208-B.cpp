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
#define f2(i,a,b) for(ll i=(a);i<=(b);i++)
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
//const int fx[] = {0, +1, 0, -1};
//const int fy[] = {-1, 0, +1, 0};
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



string s,s1;
ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=INF,l=0,sum1=0,sum=0,Max=0,Min=INF,num;
ll arr[10000000];
vector<ll>vc;
vector<ll>vvc1[20005];
map<ll,ll>mp;
map<ll,ll>::iterator it;

int main()
{
    fast;
    cin >> n ;
    f0(i,n)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        if(mp[arr[i]]==2)
        {
            counT++;
            vc.pb(arr[i]);
        }
    }


    if(vc.size()==0)
    {
       return cout << 0,0 ;
    }

    f0(i,n)
    {

        cs = 0 ;
        f2(j,i,n-1)
        {
            mp[arr[j]]--;
            if(mp[arr[j]]==1)
                cs++;
            if(cs==counT)
                ans = min(ans,j-i+1) ;
        }
  //  D(ans);


      f2(j,i,n-1)
      mp[arr[j]]++;


    }
  //  D(ans);
    cout << ans << ln ;

}
