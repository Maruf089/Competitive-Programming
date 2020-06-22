#include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 10, INF = 0x3f3f3f3f;

struct edge
{
    int to, cost, next;
}g[N*2];

int cnt, head[N];
int dep[N], dis[N], fat[N][20];

void init()
{
    cnt = 0;
    memset(head, -1, sizeof head);
}
void add_edge(int v, int u, int cost)
{
    g[cnt].to = u, g[cnt].cost = cost, g[cnt].next = head[v], head[v] = cnt++;
}
void dfs(int v, int fa, int d, int val)
{
    dep[v] = d, fat[v][0] = fa, dis[v] = val;
    for(int i = head[v]; ~i; i = g[i].next)
    {
        int u = g[i].to;
        if(u == fa) continue;
        dfs(u, v, d+1, val + g[i].cost);
    }
}
void lca_init(int n)
{
    for(int j = 1; (1<<j) <= n; j++)
        for(int i = 1; i <= n; i++)
            fat[i][j] = fat[fat[i][j-1]][j-1];
}
int lca(int v, int u)
{
    if(dep[v] < dep[u]) swap(v, u);
    int d = dep[v] - dep[u];
    for(int i = 0; (d>>i) != 0; i++)
        if((d>>i) & 1) v = fat[v][i];
    if(v == u) return v;
    for(int i = 18; i >= 0; i--)
        if(fat[v][i] != fat[u][i]) v = fat[v][i], u = fat[u][i];
    return fat[v][0];
}
int query_kth(int v, int u, int k)
{
    int t = lca(v, u);
    int len = dep[v] - dep[t] + 1;
    if(k <= len)
    {
        --k;
        for(int i = 0; (k>>i) != 0; i++)
            if((k>>i) & 1) v = fat[v][i];
        return v;
    }
    else
    {
        k = dep[u] - dep[t] - (k - len);
        for(int i = 0; (k>>i) != 0; i++)
            if((k>>i) & 1) u = fat[u][i];
        return u;
    }
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d", &n);
        int a, b, c;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c); add_edge(b, a, c);
        }
        dfs(1, 0, 1, 0);
        lca_init(n);
        char opt[20];
        while(scanf("%s", opt), opt[1] != 'O')
        {
            scanf("%d%d", &a, &b);
            if(opt[0] == 'D')
            {
                int ans = lca(a, b);
                printf("%d\n", dis[a] - 2 * dis[ans] + dis[b]);
            }
            else
            {
                scanf("%d", &c);
                printf("%d\n", query_kth(a, b, c));
            }
        }
    }
    return 0;
}
