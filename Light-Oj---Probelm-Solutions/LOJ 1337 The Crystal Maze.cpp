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
const int high = 503;

char adj[high][high];
int row, col, cnt=0, matrix[high][high];
bool visited[high][high];
int dir_x[4] = {-1, 1, 0, 0}, dir_y[4] = {0, 0, -1, 1};

void BFS(int x, int y)
{
    int ux=0, uy=0, vx=0, vy=0;

    queue<int>Q;

    visited[x][y] = true;
    cnt=0;

    if(adj[x][y] == 'C')
    {
        cnt++;

        //matrix[x][y] = cnt;
    }

    Q.push(x);
    Q.push(y);

    while(!Q.empty())
    {
        ux = Q.front();
        Q.pop();

        uy = Q.front();
        Q.pop();

        for(int i=0; i<4; i++)
        {
            vx = ux + dir_x[i];
            vy = uy + dir_y[i];

            if((vx >= 0 && vx < row) && (vy >= 0 && vy < col) && (adj[vx][vy] != '#'))
            {
                if(!visited[vx][vy])
                {
                    visited[vx][vy] = true;
                    if(adj[vx][vy] == 'C')
                        cnt++;
                    Q.push(vx);
                    Q.push(vy);
                }

                //if(cnt) matrix[vx][vy] = cnt;
            }
        }
    }

    //matrix[x][y] = cnt;
}

int main()
{
    int Q, x, y, test, tc=0, i, j;
    char ch;
    sf("%d", &test);
    while(test--)
    {
        sf("%d %d %d", &row, &col, &Q);

        mset(adj, '#');
        mset(visited, false);
        mset(matrix, -1);

        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                sf(" %c", &ch);

                adj[i][j] = ch;
            }
        }

        pf("Case %d:\n", ++tc);

        while(Q--)
        {
            cnt=0;

            sf("%d %d", &x, &y);

            x--;
            y--;

            if(matrix[x][y] != -1)
            {
                pf("%d\n", matrix[x][y]);
            }

            else
            {
                cnt = 0;
                mset(visited, false);

                BFS(x, y);

                pf("%d\n", cnt);

                for(i=0; i<row; i++)
                {
                    for(j=0; j<col; j++)
                    {
                        if(visited[i][j])
                        {
                            matrix[i][j] = cnt;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
