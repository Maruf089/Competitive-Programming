#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point

#define pb(a) push_back(a)

#define sqr(x) ((x)*(x))

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ll long long

#define ull unsigned long long

#define SZ(a) int(a.size())

#define read() freopen("input.txt", "r", stdin)

#define write() freopen("output.txt", "w", stdout)


#define ms(a,b) memset(a, b, sizeof(a))

#define all(v) v.begin(), v.end()

#define PI acos(-1.0)

#define pf printf

#define sfi(a) scanf("%d",&a);

#define sfii(a,b) scanf("%d %d",&a,&b);

#define sfl(a) scanf("%lld",&a);

#define sfll(a,b) scanf("%lld %lld",&a,&b);

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define INF 1000000000   //10e9

#define EPS 1e-9


using namespace std;
vector<int>adj_list[30009]; // Short hand as tree Only one outer node and one inner node
vector<int>weight[30009]; // Max possible 2 distances // Similar usage as adj_list // Same time updating
int path_dis_from_source[30009];
bool visited[30009];
int bfs(int source)
{
    queue<int>Q;
    Q.push(source);
    path_dis_from_source[source] = 0;
    int mx_dis = 0;
    int farthest_node;
    while(!Q.empty())
    {
        int u = Q.front() ; //Current node that we will work on now
        visited[u] = true;
        Q.pop();
        for(int cur = 0 ; cur < adj_list[u].size();cur++)
        {

            int v = adj_list[u][cur];
            if(!visited[v])
            {
            Q.push(v);

            int wt = weight[u][cur] ;
            path_dis_from_source[v] = path_dis_from_source[u] + wt;
            if( path_dis_from_source[v] > mx_dis)
            {
                mx_dis =  path_dis_from_source[v];
                farthest_node = v;
            }

            }
        }


    }
    return farthest_node;


}
int bfs2(int source)
{
    queue<int>Q;
    Q.push(source);
    path_dis_from_source[source] = 0;
    int mx_dis = 0;

    while(!Q.empty())
    {
        int u = Q.front() ; //Current node that we will work on now
        visited[u] = true;
        Q.pop();
        for(int cur = 0 ; cur < adj_list[u].size();cur++)
        {

            int v = adj_list[u][cur];
            if(!visited[v])
            {
            Q.push(v);

            int wt = weight[u][cur] ;
            path_dis_from_source[v] = path_dis_from_source[u] + wt;
            if( path_dis_from_source[v] > mx_dis)
            {
                mx_dis =  path_dis_from_source[v];

            }

            }
        }


    }
    return mx_dis;


}
int main()
{
int tc; int cas = 0;
sfi(tc);
while(tc--)
{
    int N;
    sfi(N);
    loop(i,0,N-2)
    {
        int a,b,w;
        sfii(a,b);
        sfi(w);
        adj_list[a].pb(b);
        adj_list[b].pb(a);
        weight[a].pb(w);
        weight[b].pb(w);

    }
    ms(visited,false);

    int first_node_in_tree_diameter = bfs(0) ; //finding farthest node from 0
    //cout<<first_node_in_tree_diameter;
    ms(visited,false);
    int tree_diameter  = bfs2(first_node_in_tree_diameter) ;
    CASE(cas);
    pf("%d\n",tree_diameter);

    loop(i,0,N)
    {
        adj_list[i].clear();
        weight[i].clear();
    }

}


    return 0;
}
