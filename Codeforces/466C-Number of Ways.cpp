///**Bismillahir Rahmanir Rahim.**/
//#include<bits/stdc++.h>
//#define ln '\n'
//#define pf printf
//#define sf scanf
//#define inp(x) scanf("%lld",&x)
//#define D(x) cout<< #x " = "<<x<<endl
//#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)
//
//#define f0(i,b) for(int i=0;i<(b);i++)
//#define f1(i,b) for(int i=1;i<=(b);i++)
//#define _case cout<<"Case "<<++cs<<": "
//
//#define MOD 1000000007
//#define countv(v,a) count(v.begin(),v.end(),a)
//#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
//#define mnv(v) *min_element(v.begin(),v.end())
//#define mxv(v) *max_element(v.begin(),v.end())
//#define uniq(v) v.resize( unique(all(v)) - v.begin())
//
//#define PI acos(-1)
//#define ll long long int
//#define ull unsigned long long
//
//#define vi vector <int>
//#define vll vector <ll>
//#define vs vector <string>
//#define pb push_back
//#define eb emplace_back
//#define mpii map <int,int>
//#define mpsi map <string,int>
//#define mpll map <long long,long long>
//#define MP make_pair
//#define F first
//#define S second
//
//#define GCD(a,b) __gcd(a,b)
//#define LCM(a,b) (a*(b/__gcd(a,b)))
//
//#define rev(v) reverse(v.begin(),v.end())
//#define srt(v) sort(v.begin(),v.end())
//
//#define all(v) v.begin(),v.end()
//#define MEM(a, b) memset(a, b, sizeof(a))
//
//#define fast ios_base::sync_with_stdio(false)
//
///*
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including */
//using namespace std;
////using namespace __gnu_pbds;
///*
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template<typename F, typename S>
//using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;
//*/
//
//template <class T> inline T bigmod(T p,T e,T M)
//{
//    if(e==0)return 1;
//    if(e%2==0){ll t=bigmod(p,e/2,M);return (T)((t*t)%M);}
//    return (T)((ll)bigmod(p,e-1,M)*(ll)p)%M;
//}
//
//template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//
//const ll INF = 0x3f3f3f3f3f3f3f3f;
//const long double EPS = 1e-9;
//const int inf = 0x3f3f3f3f;
///// count set bit C = (num * 0x200040008001ULL & 0x111111111111111ULL) % 0xf; /// 32 bit integer
//
///*------------------------------Graph Moves----------------------------*/
////Rotation: S -> E -> N -> W
////const int fx[] = {0, +1, 0, -1};
////const int fy[] = {-1, 0, +1, 0};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
////const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
////const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
///*---------------------------------------------------------------------*/
//
///// Bit Operations
///// inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
///// inline ll setBit(ll n, int i) { return n|(1LL<<i); }
///// inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }
//
//
//inline bool isSquare(ll x)  { ll s = sqrt(x); return (s*s==x); }
//inline bool isFib(ll x) { return isSquare(5*x*x+4)|| isSquare(5*x*x-4); }
//inline bool isPowerOfTwo(ll x)   { return ((1LL<<(ll)log2(x))==x); }
//
//typedef struct {
//    double x,y;
//   /// Point() {}
//  ///  Point(double x,double y) : x(x), y(y) {}
//} Point;
//
//double distance(Point a , Point b) {
//    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
//}
///// ************************************** Code starts here ****************************************** */
string s,s1;
ll n,m,a,b,i,j,d,t,cs=0,counT=0,k=3,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
vector<ll>vc,vcs;
map<ll,ll>mp;
int Binarysearch(int idx)
{
    int low=0,high=vcs.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(vcs[mid]<=idx) low = mid+1;
        else if(vcs[mid]>idx and vcs[mid-1]<=idx)
            return mid ;
        else if(vcs[mid]>idx and mid==0)
            return mid;
        else high = mid-1;

    }
    return -1;
}
ll CounTSubarraysum(int n,ll sum)
{
    if(sum%3!=0)
        return 0 ;
    ll counT =0 ;
    ll prefix[n];
    prefix[0] = vc[0] ;
    for(i=1;i<n;i++)
    {
        prefix[i] = prefix[i-1] + vc[i] ;
    }

    ll suffix[n];
    suffix[n-1] = vc[n-1] ;
    for(i=n-2;i>=0;i--)
    {
        suffix[i] = suffix[i+1] + vc[i] ;
    }

    for(i=0;i<n;i++)
        if(suffix[i] == sum/3)
            vcs.pb(i);
    for(i=0;i<n;i++)
    {
        if(prefix[i]==sum/3)
        {
            ll res = Binarysearch(i+1) ;
            if(res!=-1)
                counT += vcs.size()-res;
        }
    }
    return counT ;
}
int main()
{
   cin >> n ;
   f0(i,n)
   {
       cin >> a;
       vc.pb(a);
       sum += a ;
   }
   counT = CounTSubarraysum(n,sum);
   cout << counT << ln ;
}





#include <iostream>
#include <math.h>
#define f0(i,b) for(int i=0;i<(b);i++)
using namespace std;
#define D(x) cout<< #x " = "<<x<<endl
int a[1000010];
long long cnt[1000010];

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    long long s = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0)
        cout << "0\n";
    else {
        s /= 3;
        long long ss = 0;
        for(int i = n-1; i >= 0 ; --i)
        {
            ss += a[i];
            if (ss == s)
                cnt[i] = 1;
        }

        for(int i = n-2 ; i >= 0 ; --i)
            cnt[i] += cnt[i+1];


        long long ans = 0;
        ss = 0;
        for(int i = 0 ; i+2 < n ; ++i) {
            ss += a[i];
            if (ss == s)
                {ans += cnt[i+2];

                }
        }
        cout << ans << "\n";
    }
    return 0;




}
