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


typedef struct
{
    double x,y;
} Point;

double distance(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


//
//int main()
//{
//    int tst, i, j, k;
//    cin >> tst ;
//    while(tst--)
//    {
//        int n, ara[10];
//        for(i=0; i<10; i++)
//            ara[i]=0;
//        scanf("%d", &n);
//        for(i=1; i<=n; i++)
//        {
//            j = i;
//            while(j!=0)
//            {
//                k=j%10;
//                ara[k]++;
//                j/=10;
//            }
//        }
//        for(i=0; i<9; i++)
//            printf("%d ", ara[i]);
//        printf("%d\n", ara[9]);
//    }
//    return 0;
//}
//
int const lim=10001;
int dp[lim][111];
int fre[121];
void func(int n)
{
    int x=n;

    while(x!=0)
    {
        int rem=x%10;
        dp[n][rem]=1+fre[rem];
        fre[rem]=dp[n][rem];
        x=x/10;
    }
    for(int i=0; i<10; i++)
    {
        dp[n][i]=fre[i];
    }
}
int main()
{
    for(int i=1; i<=9; i++)
    {
        dp[i][i]=1;
        fre[i]=1;
        for(int j=0; j<10; j++)
        {
            dp[i][j]=fre[j];
        }
    }
    for(int i=10; i<=lim+5; i++)
    {
        func(i);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<10; i++)
        {
            if(i==9)
                cout<<dp[n][i];
            else
                cout<<dp[n][i] << " ";

        }
        cout<<endl;
    }


}
