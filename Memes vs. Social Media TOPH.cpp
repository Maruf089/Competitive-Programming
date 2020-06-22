#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define ALL(a) a.begin(), a.end()
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr)
#define IN freopen("input.txt","r+",stdin)
#define OUT freopen("output.txt","w+",stdout)

#define DBG(a) cout<< #a <<" --> "<<(a)<<endl
#define NL cout<<"\n"

template < class T1,class T2>
ostream &operator <<(ostream &os,const pair < T1,T2 > &p)
{
    os<<"{"<<p.first<<","<<p.second<<"}";
    return os;
}

const int N=1e4+5;
const int oo=1e9+7;


int parent[N];
int size[N];
int rnk[N];
int find_set(int v)
{
    return parent[v] == v ? v :  parent[v] = find_set(parent[v]);
}

void make_set(int v)
{
    parent[v] = v;
    rnk[v] = 0;
    size[v]=1;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        size[a]+=size[b];
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

pii w[N];
bool vis[N];
ll dp[N];

int32_t main()
{
    FastIO;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        make_set(i);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        union_sets(u,v);
    }
    int tot = 0;
    for(int i=1; i<=n; i++)
    {
        if(vis[find_set(i)]==0)
        {
            vis[find_set(i)] = 1;
            w[tot++]= { i, size[find_set(i)]};
        }
    }
    for(int i=0; i<=k; i++)
        dp[i]= oo;
    dp[0]=0;
    int sum = 0;
    for(int i=0; i<tot; i++)
    {
        sum+=w[i].second;
        for(int j=min(k, sum); j>0; j--)
            if(j-w[i].second >= 0 )
                dp[j]= min(dp[j], dp[j-w[i].second] + w[i].first);
            else
                dp[j]= min(dp[j],(ll)w[i].first);
    }
    cout<<dp[k]<<"\n";
}
