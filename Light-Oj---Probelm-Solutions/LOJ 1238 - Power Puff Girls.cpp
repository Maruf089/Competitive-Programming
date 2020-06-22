#include <bits/stdc++.h>
#define sc(n) scanf("%d", &n)
#define scS(n) scanf("%s", n)
#define S 23
using namespace std;
typedef long long LL;

int dirX[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dirY[] = {0, 1, 0, -1, 1, -1, -1, 1};

struct node
{
    int x, y;
    node(int p, int q)
    {
        x = p, y = q;
    }
};

char cell[S][S];
int dist[S][S];
int n, m;

int bfs(int u, int v)
{
    queue <node> Qu;
    memset(dist, -1, sizeof(dist));
    Qu.push(node(u, v));
    dist[u][v] = 0;
    while(!Qu.empty())
    {
        node i = Qu.front();
        Qu.pop();
        for(int z = 0; z < 4; z++)
        {
            int I = i.x+dirX[z], J = i.y+dirY[z];
            if(dist[I][J] != -1 || cell[I][J] == '#' || cell[I][J] == 'm')
                continue;
            if(I >= n || J >= m || I < 0 || J < 0)
                continue;
            dist[I][J] = dist[i.x][i.y]+1;
            if(cell[I][J] == 'h')
                return dist[I][J];
            Qu.push(node(I, J));
        }
    }
}

void Do()
{
    int t, cs = 0;
    sc(t);
    while(t--)
    {
        sc(n);
        sc(m);
        for(int i = 0; i < n; i++)
            scS(cell[i]);
        int mx = -INT_MAX;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(cell[i][j] == 'a' || cell[i][j] == 'b' || cell[i][j] == 'c')
                {
                    int x = bfs(i, j);
                    mx = max(mx, x);
                }
            }
        }
        printf("Case %d: %d\n", ++cs, mx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    ///freopen("inp","r",stdout);
    ///freopen("contest.txt","w",stdout);
#endif
    Do();
    return 0;
}
