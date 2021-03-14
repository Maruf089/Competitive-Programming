
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int tree[N][26], idx ;
int len[N], link[N], t ,Max ,ans;
int occurrence[N];
/// char s[N] ; /// 1-indexed
string s ;

void Init()
{
    memset(tree,0,sizeof tree);
    memset(link,0,sizeof link);
    memset(len,0,sizeof len);
    memset(occurrence,0,sizeof occurrence);

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
        Max = max(Max,len[idx]);
        link[idx] = len[idx] == 1 ? 2 : tree[x][c];
    }
    t = tree[t][c];
    occurrence[t]++;
}

int main()
{
    int t;
    cin >> t ;
    while(t--)
    {
        Max = 0 ;
        cin >> s ;
        Init();
        s = '#'+s;
        for(int j=1; j<s.size(); j++)
        {
            extend(j);
        }
        for(int j=idx;j>2;j--)
            occurrence[link[j]] += occurrence[j];
        ans = 0 ;
        for(int j=3;j<=idx;j++)
        {
            if(len[j]==Max)
                ans += occurrence[j];
        }
        cout << Max << ' ' << ans << endl;
    }
}


