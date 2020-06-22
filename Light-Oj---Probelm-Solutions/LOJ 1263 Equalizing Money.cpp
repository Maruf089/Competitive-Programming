#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define SZ(x) ((int)(x).size())
#define scl(x) scanf("%lld", &x)
#define scll(x,y) scanf("%lld %lld", &x, &y)
#define all(x) (x).begin(),(x).end()
#define mem(a,d) memset(a,d,sizeof a)
#define REP(i,n) for(int i=0;i<n;i++)
#define REV(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pri(a) cout<<a<<endl
#define prii(a,b) cout<<a<<" "<<b<<endl
using namespace std;

#define inf 12345678912
#define sz 10007

ll n,e,u,v;
ll mny[1234];
vector<int> adj[sz];
int ppl,tot,sm;
bool vis[1234];


void dfs(int u)
{
    tot += mny[u];
    ppl++;
    vis[u] = 1;

    REP(i,SZ(adj[u]))
    {
        int v = adj[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }

}

int main()
{

    ll t,cs=0;
    scl(t);
    while(t--)
    {
        sm = 0;
        scll(n,e);
        REP(i,n) scl(mny[i]), sm += mny[i];

        int fl = 0;

        REP(i,e)
        {
            scll(u,v);
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int avg = sm/n;     //each getting equal mny finally

        REP(i,n)
        {

            ppl = 0;
            tot = 0;
            if(vis[i]==0)
            {
                dfs(i);

                if(tot%ppl!=0)
                {
                    fl=1;
                    break;
                }
                else
                {
                    if(avg != tot/ppl)
                    {
                        fl =1;
                        break;
                    }
                }
            }

        }

        printf("Case %lld: ", ++cs);

        if(fl)
            puts("No");
        else
            puts("Yes");

        REP(i,sz)
            adj[i].clear();
        mem(vis,0);
    }

    return 0;
}
