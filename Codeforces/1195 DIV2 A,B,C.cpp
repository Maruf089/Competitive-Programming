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
/// count set bit C = (num * 0x200040008001ULL & 0x111111111111111ULL) % 0xf;

int dx[] = { 0, 0, 1, -1 }; /// 4 Direction
int dy[] = { 1, -1, 0, 0 };

/// int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
/// int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
/// int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


typedef struct
{
    double x,y;
} Point;

double distance(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}



string s,s1;
ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
ll arr[10000000];
vector<ll>vc;
map<ll,ll>mp;
/*
int main()
{
    cin >> n >> k;
    ll odd = true;
    while(n--)
    {
        cin >> a ;
        mp[a]++;
    }
    f1(i,k)
    {
        counT += mp[i];
        if(mp[i]&1)
        {
            if(!odd)
            {
                counT-- ;
                odd = true ;
            }
            else  odd = false;
        }
    }
    cout << counT ;

}




int main()
{
       int n, k;
    cin >> n >> k ;

    int mn = 0;
    int mx = n;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        ll _put = n - mid;
        ll sum = (_put * (_put + 1))/2;
        if(sum - mid > k) mn = mid + 1;
        else mx = mid;
    }
    cout << mn ;
}

*/

int main()
{
    cin >> n >> k;
    for(i=1; ; ++i)
    {
        counT += i ;
        if(n==(counT-k)+i)
        {
            cout << counT - k  << endl;
            break;
        }
    }
}
