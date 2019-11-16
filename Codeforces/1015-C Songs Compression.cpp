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
ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,temp=0,sum=0,Max,Min,num;
ll arr[10000000];


int main()
{
    cin >> n >> m;
    pair<ll,ll>vc[n] ;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b ;
        sum += a;

        vc[i].F = (a-b) ; vc[i].S = a;
    }


     for(ll it = 0; it<n; it++)
            cout << vc[it].F << " " << vc[it].S << endl ;


    if( sum <= m )
        return cout << 0,0;
    else
    {

        sort(vc,vc+n);
        reverse(vc,vc+n);

        /// Repeate File problem like 2 10 and 2 3 ; 2 10 placed upper but it should be lower

//        for(ll it = 0; it<n; it++)
//        {
//            if( sum <= m )
//                return cout << counT,0;
//            else
//               {
//                sum = sum - vc[it].second + vc[it].first ;
//                counT++  ; }
//        }
//        cout << -1 ;

    }


}

*/

  class myfv
    {
        public:
        long a;
        long b;
    };
    myfv arr[1000005];

    bool comp( myfv c , myfv d)
    {
        return c.a-c.b < d.a-d.b ;
    }

int main()
{

    long long n,m,i,sum = 0,k=0;
    cin >> n >> m;

    for(i=0;i<n;i++)
    {
        cin >> arr[i].a >> arr[i].b;
        sum += arr[i].a ;
    }

    if( sum <= m )
        return cout << 0, 0;

    sort( arr , arr + n , comp );

    for( i=n-1;i>=0 and sum > m ;i--)
    {
        sum = sum-arr[i].a+arr[i].b;
            k++;
    }

    if(sum>m)
        cout<<-1;
    else
        cout<<k;
}
