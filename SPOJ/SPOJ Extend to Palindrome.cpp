#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int tree[N][26], idx ;
int len[N], link[N], t , ans ;
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
    while(scanf("%s",str))
    {
        s = str;
        Init();
        Max = 0;
        n = s.size();
        ss = s;
        s = '#'+s;
        for(int j=1; j<s.size(); j++)
        {
            extend(j);
        }
        Max = len[idx];
        ans = n - Max;
        printf("%s",str);
        if(ans)
        {
            char temp[ans+9];
            for(int i=ans;i>=1;i--)
                printf("%c",s[i]);
        }
        printf("\n");
    }

}

