#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
struct eertree
{
  int sz,last;
  struct node
  {
    int next[26],len,link;
  }pal[N+2];
  void constructor(void)
  {
    memset(pal,0,sizeof(pal));
    pal[0].len=-1,pal[0].link=0;//odd root
    pal[1].len=0,pal[1].link=0;//even root
    sz=1,last=1;
  }
  void build(string s)
  {
    s="#"+s;
    for(int p=1;p<s.size();p++)
    {
      while(s[p-pal[last].len-1]!=s[p])last=pal[last].link;
      int x=pal[last].link,c=s[p]-'a';
      while(s[p-pal[x].len-1]!=s[p])x=pal[x].link;
      if(!pal[last].next[c])
      {
        pal[last].next[c]=++sz;
        pal[sz].len=pal[last].len+2;
        if(pal[sz].len==1)pal[sz].link=1;
        else pal[sz].link=pal[x].next[c];
      }
      last=pal[last].next[c];
    }
  }
};
struct node
{
  int len,link,next[26];
};
struct suffixAutomata
{
  int sz,last;node aut[N+N+2];//2*insrt function call
  suffixAutomata()
  {
    sz=0,last=0;aut[0].link=-1;
  }
  void insrt(int c)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    int p,q,cl;
    for(p=last;p!=-1&&!aut[p].next[c];p=aut[p].link)
      aut[p].next[c]=now;
    if(p==-1)
      aut[now].link=0;
    else
    {
      q=aut[p].next[c];
      if(aut[p].len+1==aut[q].len)
        aut[now].link=q;
      else
      {
        cl=++sz;aut[cl].len=aut[p].len+1;
        aut[cl].link=aut[q].link;
        memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
        for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
          aut[p].next[c]=cl;
        aut[now].link=aut[q].link=cl;
      }
    }
    last=now;
  }
};
int ans,vis[26],ds,k;
eertree aa,bb;suffixAutomata cc;
void dfs(int a,int b,int c)
{
  if(ds>=k)ans=max(ans,aa.pal[a].len);
  for(int i=0;i<26;i++)
  {
    if(aa.pal[a].next[i]&&bb.pal[b].next[i]&&cc.aut[c].next[i])
    {
      vis[i]++;if(vis[i]==1)ds++;
      dfs(aa.pal[a].next[i],bb.pal[b].next[i],cc.aut[c].next[i]);
      vis[i]--;if(vis[i]==0)ds--;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>k;string a,b,c;cin>>a>>b>>c;
  aa.constructor();bb.constructor();
  aa.build(a);bb.build(b);
  for(auto x:c)cc.insrt(x-'a');
  for(int i=0;i<26;i++)
  {
    if(aa.pal[0].next[i])
    {
      vis[i]++;ds++;
      dfs(aa.pal[0].next[i],1,0);
      vis[i]--;ds--;
    }
  }
  cout<<ans<<endl;
  return 0;
}
