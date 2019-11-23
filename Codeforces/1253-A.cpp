


#include<bits/stdc++.h>
using namespace std;
#define ln '\n'

#define pf printf
#define sf scanf

#define inp(x) scanf("%lld",&x)
#define D(x) cerr<< #x " = "<<x<<endl
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define f(a,b) for(int i=a;i<=(b);i++)
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
#define B begin()
#define E end()

#define sz size()
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b)))
//#define harmonic(n) 0.57721566490153286l+log(n)

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())

#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))

#define fast ios_base::sync_with_stdio(false)


/// ************************************** Code starts here ****************************************** */
string s,s1;

ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;


map<ll,ll>mp;

int main()
{

  cin >> t ;
  while(t--)
  {
      cin >> n ;
      int arr[n+9],brr[n+9],crr[n+9],drr[n+9];
      f0(i,n)
          cin >> arr[i];
      f0(i,n)
          cin >> brr[i];

      vector<pll>vc;
      bool temp = false,flag=false;
      f0(i,n)
      {
          d = brr[i]-arr[i];
          if(d<0)
          {
              flag = true;
              break;
          }
          if(d>0)
          {
             vc.pb({d,i+1});
          }
      }
//      for(auto i :vc)
//      {
//          cout << i.F << " dfg " << i.S <<ln;
//      }
      if(flag==true)
      {
          cout << "NO" << ln ;
          continue;
      }
      if(vc.sz>=2)
      f0(i,vc.sz-1)
      {
          if(vc[i].F!=vc[i+1].F)
          {
              flag = true;
              break;
          }
          if(vc[i].S!=vc[i+1].S-1)
          {
              flag = true ;
              break;
          }
      }
      if(flag==true)
      {
          cout << "NO" << ln ;
      }
      else cout << "YES" << ln ;
  }


}


