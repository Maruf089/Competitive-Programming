
/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
#define ln '\n'
#define pf printf
#define sf scanf
#define inp(x) scanf("%lld",&x)
#define D(x) cout<< #x " = "<<x<<endl
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define _case cout<<"Case "<<++cs<<": "

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
#define eb emplace_back
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

/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */
using namespace std;
//using namespace __gnu_pbds;
/*
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;
*/


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

typedef struct
{
    double x,y;
    /// Point() {}
    ///  Point(double x,double y) : x(x), y(y) {}
} Point;

double distance(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


mpsi mp;
int par[5002],arr[5002];
void Initialization(int n)
{
    int i ;
    for ( i = 0 ; i <= n ; i++ )
        { par[i] = i ; arr[i] = 1 ;}
}
int find_parent(int x)
{
    if(par[x]==x)
        return x;
    return par[x] = find_parent(par[x]);
}
void Make_Union(int x, int y)
{
    int U = find_parent(x);
    int V = find_parent(y);
    if(U!=V)
    {
        par[V] = U ;
        arr[U] += arr[V] ;
    }
}
bool isUnion(int x, int y)
{
    return find_parent(x)==find_parent(y);
}

int main()
{
    string s1,s2,s3;
    int node,edge;
    while(scanf("%d%d",&node,&edge)==2)
    {
        if(node == 0 && edge ==0)
        {
            break;
        }

        Initialization(node);
        for(int i=0; i<node; i++)
        {
            arr[i] = 1;
        }
        for(int i=0; i<node; i++)
        {

            cin>>s1;
            mp[s1]=i;
        }

        f0(i,edge)
        {
            cin >> s2 >> s3 ;
            int x = mp[s2] ;
            int y = mp[s3] ;
            if(!isUnion(x,y))
            {
                Make_Union(x,y);
            }
        }
        int Max = 0 ;
        f0(i,node)
        {
            Max = max(Max,arr[i]);
        }
        cout << Max << ln ;

    }
}

