#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0)
#define bfast cin.tie(0)
#define outs(x) cout << x << " "
#define outn(x) cout << x << "\n"
#define sf scanf
#define pf printf
#define nl puts("")
#define psb push_back
#define mset(c,v) memset(c , v , sizeof c)
#define loop0(n) for(int i=0; i<n; i++)
#define loop1(n) for(int i=1; i<=n; i++)
#define mpair(x , y) make_pair(x , y)
#define all(x) x.begin(), x.end()
#define pi acos(-1.0)
#define psb push_back

typedef unsigned long long ull;
typedef long long LL;
typedef vector<int>vii;
typedef vector<LL>vll;
typedef vector<string>vs;
typedef map<int, int>mpii;
typedef map<string, int>mpsi;
typedef map<char, int>mpci;
typedef map<LL, LL>mpll;

const int mod = 1000007;
const int high = 210;
const int inf = 2147483647;

char adj[high][high];
int dir_x[4]= {-1, 1, 0, 0}, dir_y[4] = {0, 0, -1, 1};
int R, C;
int FireCost[high][high], JaneCost[high][high];

struct my
{
    int x, y, c;

    my(int p, int q, int r)
    {
        x = p;
        y = q;
        c = r;
    }

    my() { }
} node;

queue<my>Q;

void Reset()
{
    for(int i=0; i<high; i++)
    {
        for(int j=0; j<high; j++)
        {
            FireCost[i][j] = inf;
            JaneCost[i][j] = inf;
        }
    }

    while(!Q.empty())
        Q.empty();
}

void BFS(int fl)
{
    while(!Q.empty())
    {
        node = Q.front();

        Q.pop();

        for(int i=0; i<4; i++)
        {
            int xx = node.x + dir_x[i];
            int yy = node.y + dir_y[i];

            if(fl == 1)
            {
                if((xx>=0 && xx<R) && (yy>=0 && yy<C) && adj[xx][yy]!='#' && JaneCost[xx][yy] == inf)
                {
                    JaneCost[xx][yy] = node.c + 1;
                    Q.push(my(xx, yy, node.c + 1));
                }
            }

            else
            {
                if((xx>=0 && xx<R) && (yy>=0 && yy<C) && adj[xx][yy]!='#' && FireCost[xx][yy] == inf)
                {
                    FireCost[xx][yy] = node.c + 1;
                    Q.push(my(xx, yy, node.c + 1));
                }
            }
        }
    }
}


int main()
{
    int test, tc=0, i, j;
    sf("%d", &test);

    while(test--)
    {
        sf("%d %d", &R, &C);

        for(i=0; i<R; i++)
            sf("%s", &adj[i]);

        Reset();

        for(i=0; i<R; i++)
        {
            for(j=0; j<C; j++)
            {
                if(adj[i][j] == 'J')
                {
                    JaneCost[i][j] = 0;
                    Q.push(my(i, j, 0));
                    break;
                }
            }
        }

        BFS(1);

        while(!Q.empty())
            Q.pop();

        for(i=0; i<R; i++)
        {
            for(j=0; j<C; j++)
            {
                if(adj[i][j] == 'F')
                {
                    FireCost[i][j] = 0;
                    Q.push(my(i, j, 0));
                }
            }
        }

        BFS(2);

        int ans = inf;

        // Column wise, 1st point and Last point

        for(i=0; i<C; i++)
        {
            if(FireCost[0][i] > JaneCost[0][i])
                ans = min(ans, JaneCost[0][i]);
            if(FireCost[R-1][i] > JaneCost[R-1][i])
                ans = min(ans, JaneCost[R-1][i]);
        }

        // Row wise, 1st point and last point

        for(i=0; i<R; i++)
        {
            if(FireCost[i][0] > JaneCost[i][0])
                ans = min(ans, JaneCost[i][0]);
            if(FireCost[i][C-1] > JaneCost[i][C-1])
                ans = min(ans, JaneCost[i][C-1]);
        }

        pf("Case %d: ", ++tc);

        if(ans == inf)
            pf("IMPOSSIBLE\n");
        else
            pf("%d\n", ans + 1);
    }

    return 0;
}
