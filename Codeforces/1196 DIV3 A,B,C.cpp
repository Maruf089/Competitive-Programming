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


#define PI acos(-1)
#define ll long long int
#define ull unsigned long long

#define vi vector <int>
#define pll pair<ll,ll>
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


#define fast ios_base::sync_with_stdio(false)
using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;
/// count set bit C = (num * 0x200040008001ULL & 0x111111111111111ULL) % 0xf; /// 32 bit integer

/*------------------------------Graph Moves----------------------------*/
//Rotation: S -> E -> N -> W


string s,s1;
ll n,m,a,b,i,X,Y,f1,f2,f3,f4,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;


/*

int main()
{
    int q;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        int n,k,od=0;
        cin>>n>>k;
        vector<int>v;

        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            if(x%2==1)
                v.push_back(i),od++;
        }
        int g=k%2,h=od%2;

        if(od>=k&&g==h)
        {
            cout<<"YES"<<endl;

            for(int j=0; j<k-1; j++)
                cout<<v[j]<<" ";

            cout<<n<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}


*/
const int fx[] = {-1, 0, +1, 0};
const int fy[] = {0, +1, 0, -1};


int main()
{


    cin >> t;
    while(t--)
    {

        cin >> n;

        map< pair<ll,ll>, ll>mp;
        map< pair<ll,ll>, ll> :: iterator it ;
        while(n--)
        {
            cin >> X >> Y >> f1>>f2>>f3>>f4;
            mp[make_pair(X,Y)]++;

            if(f1)
            {
                mp[make_pair(X+fx[0],Y+fy[0])]++;
            }
            if(f2)
                mp[make_pair(X+fx[1],Y+fy[1])]++;
            if(f3)
                mp[make_pair(X+fx[2],Y+fy[2])]++;
            if(f4)
                mp[make_pair(X+fx[3],Y+fy[3])]++;
        }

//       cout << "sdfg" << it->second << endl;

        for(it=mp.begin(); it!=mp.end(); it++)
        {
            cout << *it->second << " ";
            // pair<ll,ll> pop = it.first ;

//            if( it->second == 4 )
//            {
//                cout << 1 << pop.first << " " << pop.second << endl;
//                break;
//            }
        }
    }
}

