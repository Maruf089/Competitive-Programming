///*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*///

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%d",&x)
#define inp2(a,b) scanf("%d %d",&a,&b)
#define sf scanf
#define pf printf

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define MOD 1000000007
#define PI acos(-1)
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define F first
#define S second
#define sz size()
#define LCM(a,b) (a*(b/__gcd(a,b)))
//#define harmonic(n) 0.57721566490153286060651209+log(n)+1.0/(2*n)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))

#define fastio ios_base::sync_with_stdio(false)


/// ************************************** Code starts here ****************************************** */

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;
const int mx = (int)2e5+9;

int n,m,a,b,t,i,j,d,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
vector<int>vc[mx];
int arr[mx],st[mx],en[mx],id[mx],res[mx],cnt[mx],frequ[mx];
int ti = 1,BLK;

struct node
{
    int l,r,idx,k;
} Q[mx];

bool comp(node a,node b)
{
    if(a.l/BLK != b.l/BLK)
        return a.l/BLK < b.l/BLK ;
    else
        return a.r < b.r;
}

void dfs(int u, int p)
{
    st[u] = ti;
    for(auto v: vc[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
    }
    en[u] = ti;
    id[ti] = u;
    ++ti;
}

int main()
{

    scanf("%d %d",&n,&m);
    BLK = sqrt(n);

    for(i=1;i<=n;i++)
     scanf("%d",&arr[i]);

    f0(i, n-1)
    {
        int u,v;
         scanf("%d %d",&u,&v);
        vc[u].pb(v);
        vc[v].pb(u);
    }
    dfs(1,0);

    f0(i,m)
    {
        int v,k;
        inp2(v,k);
        Q[i].l = st[v];
        Q[i].r = en[v];
        Q[i].idx = i;
        Q[i].k = k ;
    }
    sort(Q,Q+m,comp);

    int ML = 0, MR = -1 ;

    for(i=0; i<m; i++)
    {
        int L =Q[i].l;
        int R = Q[i].r;
        int idx = Q[i].idx;
        int k = Q[i].k;

        /// extend range
        while(MR<R)
        {
            MR++;
            int node = id[MR];
            int color = arr[node];
            cnt[color]++;
            if(cnt[color]>=0)
            frequ[cnt[color]]++;

        }
        while(ML>L)
        {
            ML--;
            int node = id[ML];
            int color = arr[node];
            cnt[color]++;
            if(cnt[color]>=0)
            frequ[cnt[color]]++;
        }

        /// reduce range
        while(MR>R)
        {
            int node = id[MR];
            int color = arr[node];
            if(cnt[color]>=0)
            frequ[cnt[color]]--;
            cnt[color]--;
            MR--;
        }
        while(ML<L)
        {
            int node = id[ML];
            int color = arr[node];
            if(cnt[color]>=0)
            frequ[cnt[color]]--;
            cnt[color]--;
            ML++;
        }

        res[idx] = frequ[k];
    }

    for(i=0;i<m;i++)
     printf("%d\n",res[i]);

    /// Comment the debugger section
}
