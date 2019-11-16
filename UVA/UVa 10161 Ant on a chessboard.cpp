/**Bismillahir Rahmanir Rahim.**/

#include<bits/stdc++.h>
#define endl '\n'
#define sf scanf
#define pf printf
#define NL printf("\n")
#define SP printf(" ")


#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))
#define _case cout<<"Case "<<++cs<<": "
#define lp(loop,start,end) for(ll loop=start;loop<=end;loop++)
#define lpd(loop,start,end) for(ll loop=end;loop>=start;loop--)

#define D(x) cout<< #x " = "<<x<<endl
#define cout(case)   cout << "Case " << ++cs << ": "
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)


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

#define INF 10^18
#define MOD 1000000007
#define countv(v,a) count(v.begin(),v.end(),a)
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define uniq(v) v.resize( unique(all(v)) - v.begin())


#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())

#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout)

string s,s1;
ll m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum=0,Max,Min,num;
ll n,temp;

int main()
{

    while(1)
    {
        sf("%lld",&n);
     if(n==0)
        break;
        if( n == 1 )
        {
            pf("1 1\n");
            continue;
        }

        temp = sqrt(n);
        temp*temp==n?temp:temp++;
        ll  diagonal_value = (ll)(temp*(temp-1)+1);
 // D(diagonal_value);
// D(temp);
        if(diagonal_value==n)
        {
            pf("%lld %lld\n",temp,temp);
            continue;
        }

        ans = temp-abs(diagonal_value-n);
        if(temp&1)
        {
            if(n > diagonal_value )
                pf("%lld %lld\n",ans,temp);
            else
                pf("%lld %lld\n",temp,ans);
        }
        else
        {
            if(n < diagonal_value )
                pf("%lld %lld\n",ans,temp);
            else
                pf("%lld %lld\n",temp,ans);
        }

    }


}

