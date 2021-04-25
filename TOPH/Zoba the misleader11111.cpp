#include <bits/stdc++.h>
using namespace std;
const int MX=1000006;
struct node{
    int len,link,to[26];
};
node pt[2][MX];
int size,last;
char s1[MX],s2[MX],s3[MX];
int num[MX];
bool vis1[MX],vis2[MX];
vector <int> id[MX];
void init_node(int n,int z)
{
    pt[z][n].len=0;
    pt[z][n].link=-1;
    memset(pt[z][n].to,-1,sizeof(pt[z][n].to));
}
void init_pt(int z)
{
    init_node(0,z);
    init_node(1,z);
    pt[z][0].len=pt[z][0].link=-1;
    pt[z][1].link=0;
    size=2,last=1;
}
int find(int n,char s[],int i,int z)
{
    while(n){
        int j=i-pt[z][n].len-1;
        if(j>=0 && s[i]==s[j]) return n;
        n=pt[z][n].link;
    }
    return n;
}
void extend(char s[],int i,int z)
{
    int c=s[i]-97;
    int n=find(last,s,i,z);
    if(pt[z][n].to[c]==-1){
        int m=size++;
        init_node(m,z);
        pt[z][n].to[c]=m;
        pt[z][m].len=pt[z][n].len+2;
        if(pt[z][m].len==1) pt[z][m].link=1;
        else{
            int v=find(pt[z][n].link,s,i,z);
            pt[z][m].link=pt[z][v].to[c];
        }
        if(z) num[m]=(num[n]|(1<<c));
        last=m;
    }
    else last=pt[z][n].to[c];
}
void f(int u,int v,int k)
{
    int p=__builtin_popcount(num[u]);
    if(pt[1][u].len>1 && p>=k) vis1[v]=true;
    for(int c=0;c<26;c++){
        if(pt[0][v].to[c]==-1) continue;
        if(pt[1][u].to[c]==-1) continue;
        f(pt[1][u].to[c],pt[0][v].to[c],k);
    }
}
int find_it(int u,int c)
{
    while(u && (pt[0][u].to[c]==-1 || pt[0][u].len%2)){
        u=pt[0][u].link;
    }
    if(u) return pt[0][u].to[c];
    return 1;
}
int main()
{
    int k,ans=0;
    scanf("%d %s %s %s",&k,s1,s2,s3);
    int n=strlen(s1),m=strlen(s2),l=strlen(s3);
    init_pt(1);
    for(int i=0;i<n;i++) extend(s1,i,1);
    init_pt(0);
    for(int i=0;i<m;i++) extend(s2,i,0);
    for(int c=0;c<26;c++){
        if(pt[1][0].to[c]==-1) continue;
        f(pt[1][0].to[c],1,k);
    }
    for(int i=0,u=1;i<l;i++){
        int c=s3[i]-97;
        u=find_it(u,c);
        vis2[u]=true;
        id[pt[0][u].len].push_back(u);
    }
    for(int i=m;i>0;i--){
        int sz=id[i].size();
        for(int j=0;j<sz;j++){
            int u=id[i][j];
            int v=pt[0][u].link;
            vis2[v]|=vis2[u];
        }
    }
    for(int u=2;u<size;u++){
        if(!vis1[u] || !vis2[u]) continue;
        int h=pt[0][u].len+1;
        ans=max(ans,h);
    }
    printf("%d\n",ans);
    return 0;
}