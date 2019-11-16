#include<bits/stdc++.h>
#define endl '\n'
#define sf scanf
#define sfi(a) sf("%d",&a)
#define sfl(a) sf("%lld",&a)
#define sff(a,b) sf("%d %d",&a,&b)
#define sffl(a,b) sf("%lld %lld",&a,&b)
#define sfff(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c) sf("%lld %lld %lld",&a,&b,&c)
#define pf printf
#define pfi(a) pf("%d\n",a)
#define pfl(a) pf("%lld\n",a)
#define pffi(a,b) pf("%d %d\n",a,b)
#define pffl(a,b) pf("%lld %lld\n",a,b)
#define _case cout<<"Case "<<++cs<<": "
#define FOR(i,a,n) for(i=0;i<n;i++)
#define FORa(i,b,n) for(i=1;i<=n;i++)

#define PI acos(-1)
#define ll long long int
#define ull unsigned long long

#define rev(v) reverse(v.begin(),v.end())
#define sort(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define srt(v) sort(v.begin(),v.end())

#define vi vector <int>
#define vs vector <string>
#define PB push_back
#define mpii map <int,int>
#define mpsi map <int,int>
#define mpll map <long long,long long>
#define MP make_pair
#define F first
#define S second

#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b)))
#define MEM(a, b) memset(a, b, sizeof(a))


#define INF 10^18
#define MOD 1000000007
#define countv(v,a) count(v.begin(),v.end(),a)
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define uniq(v) v.resize( unique(all(v)) - v.begin())

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout)
priority_queue<ll>pq;
int main()
{
    ll n,i,j,counT=0,k,l=0,m=0,temp=0;
    sfffl(n,m,k);
    ll arr[n+1],pro[n+1];
    k = m+k;
    FOR(i,a,n)
    cin>>arr[i];

    FOR(i,a,n){
    cin>>pro[i];
    pq.push(abs(arr[i]-pro[i]));
    }
    while(k>0)
    {
        temp = pq.top();
        cout<<temp<<"  t  ";
        pq.pop();
        cout<<abs(temp-1)<<endl;
        pq.push(abs(temp-1));
        k--;
    }
    while(!pq.empty())
    {
        ll cur = pq.top();
        pq.pop();
        counT += cur*cur;
    }
    cout<<counT<<endl;

}
