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

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;


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


typedef struct {
    double x,y;
} Point;

double distance(Point a , Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

/*

string s,s1;
ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
ll arr[10000000];
vector<ll>vc;
map<ll,ll>mp;

ll f(ll n)
{
   ll  sum = 0;
    while(n)
    {
        sum += n %10;
        n /=10;
    }
    return sum ;
}
int main()
{
    cin >> n ;

    for(i=n;;i++)
    {
        if(f(i)%4==0)
        {
            cout << i ;
            break;
        }
    }

}






int main()
{

   cin >> t;
   while(t--)
   {

       cin >> n >> k ;
       cs= 0;ll arr[n+9];
       while(n--)
       {
           cin >> arr[cs];
           cs++;
       }
       sort(arr,arr+cs);
       d = arr[0]+k;
       ans = arr[cs-1]-k;
       Max = max(d,ans);
//D(d),D(ans);
//D(Max);
       if(d<ans)
       {
           cout << "-1" << ln;
           continue;
       }
       cout << Max << ln ;
   }

}



int main()
{


 cin >> t;
    while(t--){
        ll k,n,a,b;
        cin >> k >> n >> a >> b;
        if(k >= n * b + 1){
            cout << min(n,(k-n*b-1)/(a-b)) << '\n';
        }
        else
            cout << "-1\n" ;


    }
}




*/

int main()
{
   int T;
    cin >> T;
    for(int cs = 1; cs <= T; cs++)
    {
        ll n;
        cin >> n;
        map<ll,ll> mp, vis;
        for(ll i = 1; i <= n; i++){
            ll x;
            cin >> x;
            mp[x]++;
            vis[i] = 0;
        }
        ll ans = 0;
        for(auto x: mp){
            if(vis[mp[x.first]] == 0){
                ans += mp[x.first];
                vis[mp[x.first]]  = 1;
            }
            else{
                while(mp[x.first] > 0){
                    mp[x.first]--;
                    if(vis[mp[x.first]] == 0){
                        ans += mp[x.first];
                        vis[mp[x.first]] = 1;
                        break;
                    }
                }
            }
           // cerr << x.first << " "<<x.second << endl;
        }
        cout << ans << endl;
    }




}