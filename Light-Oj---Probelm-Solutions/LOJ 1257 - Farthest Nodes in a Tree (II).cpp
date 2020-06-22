#include <bits/stdc++.h>

using namespace std;
const int infinity=1000000000;
vector<int>v[31000];
vector<int>cost[31000];
int lev[31000];
int level[31000];
int n;
void bfs_one(int src)
{
    queue<int>q;
    for(int i=0; i<n; i++)
        lev[i]=infinity;
    q.push(src);
    lev[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        int ucost=lev[u];
        q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            int p=v[u][i];
            int vcost=cost[u][i]+ucost;
            if(lev[p]>vcost)
            {
                q.push(p);
                lev[p]=vcost;
            }
        }
    }
}
void bfs_two(int src)
{
    queue<int>q;
    for(int i=0; i<n; i++)
        level[i]=infinity;
    q.push(src);
    level[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        int ucost=level[u];
        q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            int p=v[u][i];
            int vcost=cost[u][i]+ucost;
            if(level[p]>vcost)
            {
                q.push(p);
                level[p]=vcost;
            }
        }
    }
}
int main()
{
    int t,l=1;
    cin>>t;
    //freopen("u.txt","w",stdout);
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n-1; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back(b);
            v[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);

        }
        int mx=0,src=0;
        bfs_one(0);
        for(int i=0; i<n; i++)
        {
            if(lev[i]>=mx)
            {
                mx=lev[i];
                src=i;
            }
        }
        bfs_one(src);
        mx=0;
        int des;
        for(int i=0; i<n; i++)
        {
            if(lev[i]>mx)
            {
                mx=lev[i];
                des=i;
            }
        }
        bfs_two(des);
        printf("Case %d:\n",l++);
        for(int i=0; i<=n-1; i++)
        {
            int p=max(lev[i],level[i]);
            printf("%d\n",p);
        }
        //printf("%d\n",mx);
        for(int i=0; i<=31000; i++)
        {
            v[i].clear();
            cost[i].clear();
        }

    }
    return 0;
}
