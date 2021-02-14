#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)

const int N = 10006;

int n, m;
vector<int>g[N], topsort;
bool vis[N], test;

void init()
{
    for (int i = 0;  i <= n; i++)
    {
        g[i].clear();
        vis[i] = 0;
    }
    topsort.clear();
}

void dfs(int u)
{
    vis[u] = true;
    for (auto &v : g[u])
    {
        if (vis[v])
            continue;
        dfs(v);
    }
    if (test)
        topsort.push_back(u);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++)
    {
        sii(n, m);
        init();
        for (int i = 0; i < m; i++)
        {
            int a, b;
            sii(a, b);
            g[a].push_back(b);
            //g[b].push_back(a);
        }
        test = true;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs(i);
        }
        test = false;
        for (int i = 1; i <= n; i++)
            vis[i] = false;
        reverse(topsort.begin(), topsort.end());
///        dbg(topsort);

        for (auto &x : topsort)
        {
            if (!vis[x])
            {
                dfs(x);
                ans++;
            }
        }
        printf("Case %d: %d\n", cs, ans);
    }

}
