


#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define pf printf
#define sf scanf
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)

#define D(x) cerr<< #x " = "<<x<<endl
#define dbg(x) cerr << #x << " = " << x << endl;
#define D2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define D3(x, y,z) cerr << #x << " = " << x << ", " << #y << " = " << y << " " << #z << " = " << z << endl;
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f(a,b) for(int i=a;i<=(b);i++)
#define test_case(t)    for(int z=1;z<=t;z++)
#define _case      printf("Case %d: ",z)

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


/// ************************************** Code starts here ****************************************** */
string s,s1;
ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
vector<ll>vc;
map<ll,ll>mp;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int arr[5],f;

        cin>>arr[0]>>arr[1]>>arr[2];

        sort(arr,arr+3);
        ans=0;

        if(arr[0]==arr[1]&&arr[1]==arr[2])
            f=1;
        else if(arr[0]==arr[1]&&arr[1]!=arr[2])
        {
            arr[0]++,arr[1]++;

            if(arr[1]!=arr[2])
                arr[2]--;
        }
        else if(arr[0]!=arr[1]&&arr[1]==arr[2])
        {
            arr[1]--,arr[2]--;

            if(arr[0]!=arr[1])
                arr[0]++;
        }
        else
        {
            arr[0]++;

            if(arr[0]!=arr[2])
                arr[2]--;
        }

        ans =arr[2]-arr[1]+arr[2]-arr[0]+arr[1]-arr[0];

        cout<<ans<<endl;
    }
}

