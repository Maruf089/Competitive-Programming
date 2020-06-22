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
typedef queue<int>qii;

const int mod = 1000007;
const int high = 10003;

vii adj[high], city;
int on_visit[high] = {0};
bool visited[high];

void adj_clear()
{
    for(int i=0; i<high; i++)
    {
        adj[i].clear();
    }
}

void BFS (int s)
{
    qii Q;
    Q.empty();

    memset(visited, false, sizeof visited);

    visited[s] = true;

    on_visit[s]++;

    Q.push (s);

    while (!Q.empty())
    {
        int u = Q.front();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(!visited[v])
            {
                on_visit[v]++;
                visited[v] = true;
                Q.push(v);
            }
        }

        Q.pop();
    }
}


int main()
{
    //fast;
    int t, tc=0, k, n, m, i, x, u, v;
    sf("%d", &t);
    while(t--)
    {
        city.clear();
        adj_clear();
        memset(on_visit, 0, sizeof on_visit);

        sf("%d %d %d", &k, &n, &m);

        for(i=0; i<k; i++)
        {
            sf("%d", &x);
            city.psb(x);
        }

        for(i=0; i<m; i++)
        {
            sf("%d %d", &u, &v);

            adj[u].psb(v);
        }

        for(i=0; i<k; i++)
        {
            BFS(city[i]);
        }

        int cnt=0;

        for(i=0; i<high; i++)
        {
            if(on_visit[i] == k)
                cnt++;
        }

        pf("Case %d: %d\n", ++tc, cnt);
    }

    return 0;
}
