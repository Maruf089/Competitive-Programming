#include<bits/stdc++.h>
#define endl '\n'
#define sf scanf
#define sfi(a) sf("%d",&a)
#define sfl(a) sf("%lld",&a)
#define sffi(a,b) sf("%d %d",&a,&b)
#define sffl(a,b) sf("%lld %lld",&a,&b)
#define sfffi(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c) sf("%lld %lld %lld",&a,&b,&c)
#define pf printf
#define pfi(a) pf("%d\n",a)
#define pfl(a) pf("%lld\n",a)
#define pffi(a,b) pf("%d %d\n",a,b)
#define pffl(a,b) pf("%lld %lld\n",a,b)
#define _case cout<<"Case "<<++cs<<": "
#define lp(loop,start,end) for(ll loop=start;loop<end;loop++)
#define lpd(loop,start,end) for(ll loop=end;loop>start;loop--)

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
#define counT(ch) count(s.begin(), s.end(), 'ch');

#define rev(arr,n) reverse(arr,arr+n);
#define srt(arr,n) srt(arr,arr+n);
#define rev(v) reverse(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define srt(v) sort(v.begin(),v.end())
#define MEM(a, b) memset(a, b, sizeof(a))

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout)
string s,s1;
int a,b,x,str[1000];
int main(){
	cin >> a >> b >> x;

	if(a > b){
		for(int i = 0; i <= x; ++i){
			if(i % 2){
				str[i] = 1;
				b--;
			}
			else{
				str[i] = 0;
				a--;
			}
		}
	}
	else{
		for(int i = 0; i <= x; ++i){
			if(i % 2){
				str[i] = 0;
				a--;
			}
			else{
				str[i] = 1;
				b--;
			}
		}
	}

	for(int i = 0; i <= x; ++i){
		cout << str[i];
		if(str[i] == 0){
			while(a){
				cout << 0;
				a--;
			}
		}
		else{
			while(b){
				cout << 1;
				b--;
			}
		}
	}
}

