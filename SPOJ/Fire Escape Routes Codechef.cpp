#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <int> adjlist[100001];
int vis[100001];
int csize;
void dfs(int node)
{
    vis[node]=1;
    csize++;
    for(int child:adjlist[node])
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
    }

}

int main()
{
    int t,n,m,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int j=1; j<=n; j++)
        {
            vis[j]=0;
            adjlist[j].clear();
        }
        int cc=0;
        long long int ways=1;
        while(m--)
        {
            cin>>a>>b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                csize=0;
                dfs(i);
                cc++;
                ways=(ways*csize)%1000000007;
            }
        }
        cout<<cc<<" "<<ways<<"\n";
    }





}
