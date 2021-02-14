#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int tree[N][26], idx ;
int len[N], link[N], t , cs = 0 ,ans ;
/// char s[N] ; /// 1-indexed
char str[N];
string s ,ss;
int Max = 0, n;
void Init()
{
    memset(tree,0,sizeof tree);
    memset(link,0,sizeof link);
    memset(len,0,sizeof len);

    len[1] = -1, link[1] = 1 ;
    len[2] = 0, link[2] = 1 ;
    idx = t = 2 ;
}

void extend(int p)
{
    while(s[p-len[t]-1] != s[p] )
        t = link[t] ;
    int x = link[t], c = s[p] - 'a' ;
    while(s[p-len[x]-1]!=s[p])
        x = link[x] ;

    if(!tree[t][c])
    {
        tree[t][c] = ++idx;
        len[idx] = len[t] + 2 ;
        link[idx] = len[idx] == 1 ? 2 : tree[x][c];
    }
    t = tree[t][c];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        s = str;
        Init();
        Max = 0;
        n = s.size();
        s = '#'+s;
        for(int j=1; j<s.size(); j++)
        {
            extend(j);
        }
        Max = len[idx];
        ans = n - Max;
        printf("Case %d: %d\n",++cs,n+ans);
    }

}


