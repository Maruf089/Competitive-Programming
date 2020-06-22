#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pii pair<int, int>

const int MAX = 300;
int id[MAX], nodes, edges, cnt = 0;
pair<ll, pii> p[MAX];
vector<int>edge;

void initialize()
{
    for(int i = 0; i < MAX; i++)
        id[i] = i;
}
int root(int x)
{
    if(id[x] == x)
        return x;
    return id[x] = root(id[x]);
}
void make_union(int x, int y)
{
    id[root(x)] = id[root(y)];
}
ll Kruskal()
{
    initialize();
    cnt = 0;
    int x, y, flag = 0;
    ll cost, minimumcost = 0;
    for(int i = 0; i < edges; i++)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x)!=root(y))
        {
            flag++;
            cnt++;
            edge.push_back(i);
            minimumcost += cost;
            make_union(x,y);
        }
    }
    if(flag==nodes-1)
        return minimumcost;
    return -1;
}
ll SBMST() ///function to find second best MST
{
    ll maximum = 1e18;

    for(int j = 0; j < cnt; j++)
    {
        initialize();
        int x, y, flag = 0;
        ll cost, minimumcost = 0;
        for(int i = 0; i < edges; i++)
        {
            if(edge[j]!=i) ///age use hoise emn value baad dibo
            {
                x = p[i].second.first;
                y = p[i].second.second;
                cost = p[i].first;
                if(root(x)!=root(y))
                {
                    flag++;
                    minimumcost += cost;
                    make_union(x,y);
                }
            }
        }
//cout<<minimumcost<<endl;
        if(flag==nodes-1)
            maximum = min(minimumcost,maximum);
///minimum value ta nibo
    }
    if(maximum!=1e18)
        return maximum;
    return -1;
}

int main()
{
    int T;
    cin>>T;

    for(int t = 1; t <= T; t++)
    {
        int u, v;
        ll weight;
        cin>>nodes>>edges;
        for(int i = 0; i < edges; i++)
        {
            cin>>u>>v>>weight;
            p[i] = mp(weight, mp(u,v));
        }
        sort(p, p + edges);

        cout<<"Case #"<<t<<" : ";
        if(Kruskal()==-1)
            cout<<"No way"<<endl;
        else
        {
            ll minimumcost = SBMST();
            if(minimumcost==-1)
                cout<<"No second way"<<endl;
            else
                cout<<minimumcost<<endl;
        }
        for(int i = 0; i < MAX; i++) /// Reset
        {
            p[i].first = 0;
            p[i].second.first = 0;
            p[i].second.first = 0;
        }
        edge.clear();
    }
    return 0;
}

