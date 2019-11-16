#include<bits/stdc++.h>
#define endl '\n'
#define sf scanf
#define pf printf

#define _case cout<<"Case "<<++cs<<": "
#define lp(loop,start,end) for(ll loop=start;loop<=end;loop++)
#define lpd(loop,start,end) for(ll loop=end;loop>=start;loop--)

#define D(x) cout<< #x " = "<<x<<endl
#define cout(case)   cout << "Case " << ++cs << ": " ;
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

/*
string s,s1;
ll n,m,a,b,i,j,t,cs=0,r=0,k,l=0,temp=0,sum=0,Max,Min,num;
ll arr[10000000];
vector<ll>vc;
map<ll,ll>mp;

int main()
{
    cin>>t;
    while(t--)
    {
        char ch;
        cin>> ch >> n;

        if( ch == 'L')
        {
            l++;
            mp[n] = -l;
        }
        else if( ch == 'R')
        {
            r++;
            mp[n] = r;
        }

        else if (mp[n] > 0)
            cout << min(r-mp[n], l+mp[n]-1) << '\n';
        else
        cout << min(l+mp[n], r-mp[n]-1) << '\n';

        /// D(l);D(r);D(mp[n]);
    }


}


*/

deque<ll>v;
ll a[(int)6e5];
int main()
{
   // fast;
    ll i,j,k,n,m,q,l=3e5,r=3e5;
    char ch;
    cin>>q;
    while(q--){
        cin>>ch>>n;
        if(ch=='L'){
            a[n]=l-1;
            l--;
            v.push_front(a[n]);
        }
        else if(ch=='R'){
            a[n]=r+1;
            r++;
            v.push_back(a[n]);
        }
        else{
            ll x=a[n];
            ll le=0,ri=v.size()-1;
            ll ans=0;
            while(le<=ri){
                ll mid=(le+ri)/2;
                if(v[mid]==x){
                    ans=mid;
                    break;
                }
                else if(x<v[mid]) ri=mid-1;
                else le=mid+1;
            }
            cout<<min(ans,(ll)v.size()-1-ans)<<endl;
        }
    }

}
