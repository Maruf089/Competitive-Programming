#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << " -- " << #x << ": " << (x) << "\n"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long INF = 200000000000000000LL;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;


#define ln '\n'
#define sf scanf
#define pf printf

#define D(x) cout<< #x " = "<<x<<endl
#define cout(case)   cout << "Case " << ++cs << ": " ;
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)


#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define MOD 1000000007
#define countv(v,a) count(v.begin(),v.end(),a)
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())


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


#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())

#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))



int dx[] = { 0, 0, 1, -1 }; /// 4 Direction
int dy[] = { 1, -1, 0, 0 };


string s,s1;
ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
ll arr[10000000];
vector<ll>vc;
map<ll,ll>mp;

int main()
{
    cin >> n ;
    while(n--)
    {
        cin >> s >> s1 ;
        cs = 0,k=0 ;
        counT=0;
        l = s1.size();
        if(s1.size()<s.size() || s[0]!=s1[0])
        {
            cout << "NO" << endl;
            continue;
        }

        for(i=0;i<s1.size();i++)
        {
        //    D(s[cs]);D(s1[i]);

          if(cs>=s.size())
           {
            if(s1[i]!=s1[i-1])
            {
                 cout << "NO" << endl;
                 k = 1 ;
                 break;
            }
           }
            else if(s1[i]==s[cs])
            {
                cs++;
                counT++;
            }
            else if(s1[i]!=s[cs-1] )
            {
                 cout << "NO" << endl;
                 k = 1 ;
                 break;
            }








        }
        if(!k)
        cout << "YES" << endl;
    }






}

