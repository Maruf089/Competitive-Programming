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

#define fast ios_base::sync_with_stdio(false)
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



string s,s1;
ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;

vector<ll>vc;
map<ll,ll>mp;


/*
int main()
{
    ll one=0,zero = 0 ;


    cin >> n ;

    cin >> s ;

    l = s.size();

    if(n==1)
    {
        return cout << 1 << ln << s << endl,0;
    }


    f0(i,s.size())
    {
        if(s[i]=='1')
            one++;
        else
            zero++;
    }

    if(one!=zero)
        return cout << 1 << ln << s << endl,0;

    cout << 2 << ln;
    cout << s[0] << " ";

    for(i=1;i<l;i++)
    cout << s[i];

}


*/

int main()
{
    cin>>n;
    vector<int>u,v;

    int a[n+10];

    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a,a+n);

    for(int i=0; i<n; i=i+2)
        u.push_back(a[i]);

    for(int i=1; i<n; i=i+2)
        v.push_back(a[i]);

    int l=v[0],r=u[1];
    if(l+r<=u[0])
        return cout<<"NO",0;

    for(int i=1; i<u.size()-1; i++)
    {
        l=u[i-1],r=u[i+1];
        if(l+r<=u[i])
            return cout<<"NO",0;
    }

    int x=u.size()-1,y=v.size();
    l=u[x-1],r=v[y-1];
    if(l+r<=u[x])
        return cout<<"NO",0;

    l=u[0],r=v[1];
    if(n==3)
        r=u[1];
    if(l+r<=v[0])
        return cout<<"NO",0;

    for(int i=1; i<v.size()-1; i++)
    {
        l=v[i-1],r=v[i+1];
        if(l+r<=v[i])
            return cout<<"NO",0;
    }
    if(n>3)
    {
        l=v[y-2],r=u[x];
        if(l+r<=v[y-1])
            return cout<<"NO",0;
    }
    cout<<"YES"<<endl;

    for(int i=0; i<u.size(); i++)
        cout<<u[i]<<" ";

    for(int i=y-1; i>=0; i--)
        cout<<v[i]<<" ";



}




/*
int main()
{
    cin >> n ;
    ll arr[n+9];
    f0(i,n)
    {
        cin >> arr[i];
        vc.pb(arr[i]);
    }
    vector<ll>c_sum(n+9,0);
    for(i=1;i<=n;i++)
    {
        c_sum[i] = c_sum[i-1] + vc[i-1] ;
    }
    cin >> a ;
    while(a--)
    {
        ll l ,r ;
        cin >> l >> r ;
        cout << (c_sum[r] - c_sum[l-1] ) / 10 << ln ;
    }


}






const int mxn = 1e5+5;
int tree[4*mxn], n,q, a[mxn];

void build(int node, int tl, int tr){

    if(tl == tr){
        tree[node] = a[tl];
    }
    else{
        int tm = (tl + tr) >> 1;
        build(node*2, tl, tm);
        build((node*2)+1, tm+1, tr);

        tree[node] = (tree[node*2] + tree[(node*2)+1]);
    }


}

int sum(int node, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }
    if(l == tl && r == tr){
        return tree[node];
    }
    int tm = (tl + tr) >> 1;
    return (sum (node*2, tl, tm, l, min(r, tm)) + sum((node*2) + 1, tm+1, tr, max(l, tm+1), r));
}


/// C

int main(){

    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> q;

    for(int que = 1; que <= q; ++que){
        int l,r;
        cin >> l >> r;
        int ans = sum(1,1,n,l,r);
        cout << ans / 10 << endl;
    }
}


*/
