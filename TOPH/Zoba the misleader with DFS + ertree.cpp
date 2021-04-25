///****In the name of Allah, most Gracious, most Compassionate****//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define NL cout<<"\n";
#define ALL(a) a.begin(), a.end()
#define DBG(a) cout<< #a <<" --> "<<(a)<<endl;
#define FastIO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define IN freopen("input.txt","r+",stdin)
#define OUT freopen("output.txt","w+",stdout)

template < class T1,class T2>
ostream &operator <<(ostream &os,const pair < T1,T2 > &p)
{
    os<<"{"<<p.first<<","<<p.second<<"}";
    return os;
}

const int MAXN=1e6+6;
const int oo=1e9+7;

namespace e1 {

struct node {
    int next[26];
    int len;
    int sufflink;
    int num;
    int mask;
};

int len;
char *s;
node tree[MAXN];
int num;            // node 1 - root with len -1, node 2 - root with len 0
int suff;           // max suffix palindrome
long long ans;

bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = tree[cur].sufflink;
    }
    if (tree[cur].next[let]) {
        suff = tree[cur].next[let];
        return false;
    }

    num++;
    suff = num;
    tree[num].mask = tree[cur].mask|(1<<let);
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;

    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }
    }

    tree[num].num = 1 + tree[tree[num].sufflink].num;

    return true;
}

void initTree() {
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
}
}
namespace e2 {

struct node {
    int next[26];
    int len;
    int sufflink;
    int num;
};

int len;
char *s;
node tree[MAXN];
int num;            // node 1 - root with len -1, node 2 - root with len 0
int suff;           // max suffix palindrome
long long ans;

bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = tree[cur].sufflink;
    }
    if (tree[cur].next[let]) {
        suff = tree[cur].next[let];
        return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;

    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }
    }

    tree[num].num = 1 + tree[tree[num].sufflink].num;

    return true;
}

void initTree() {
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
}
}

int  suf[MAXN];
vector<int > r_suf[MAXN];
bool freq[MAXN];
char ss[3][MAXN];
int k;
void bild_Suffix_link()
{
    queue < int > q;
    int a, cur;
    r_suf[0].push_back(2);
    suf[2]=0;
    q.push(2);
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        for(int i = 0; i<26; i++)
        {
            if(e2::tree[a].next[i]==0)
                continue;
            q.push(e2::tree[a].next[i]);
            cur = suf[a];
            while(cur!=0 && e2::tree[cur].next[i]==0)
                cur = suf[cur];
            if(cur==0)
                cur = 2;
            else
                cur =e2::tree[cur].next[i];
            suf[e2::tree[a].next[i]] = cur;
            r_suf[cur].push_back(e2::tree[a].next[i]);
        }
    }
}

void dfs(int u , string s)
{

    DBG(s);
    DBG(freq[u]);
    for(int i=0;i<26;i++)
        if(e2::tree[u].next[i]) dfs(e2::tree[u].next[i] , s+((char)(i+'a')));

}
void match(char * text)
{

    int now=2;
    for(int i = 0; text[i]; i++) {
		char c = text[i]-'a';
		while(now!=0 && e2::tree[now].next[c]==0)
            now = suf[now];
        if(now==0) now=2;
        else
            now= e2::tree[now].next[c];

		freq[now]=1;
	}
}
bool dfs2(int u )
{
    for(int v: r_suf[u])
    {
        freq[u]|=dfs2(v);
    }
    return freq[u];
}

int  ans(int u1 ,int u2)
{
    int ret=0;
    for(int i=0;i<26;i++)
    {
        if(e1::tree[u1].next[i] != 0 and e2::tree[u2].next[i]!=0)
        {
            ret= max(ret ,ans(e1::tree[u1].next[i] ,e2::tree[u2].next[i] ) );
        }
    }
    if(e1::tree[u1].len >1 and freq[u2] and __builtin_popcount(e1::tree[u1].mask)>=k)
    ret =max(ret , e1::tree[u1].len);
    return ret;
}

int32_t main()
{

    scanf("%d",&k);
    scanf(" %s",ss[0]);
    scanf(" %s",ss[1]);
    scanf(" %s",ss[2]);
    e1::initTree();
    e2::initTree();
    e1::s=ss[0];
    e2::s=ss[1];
    for(int i=0;e1::s[i];i++) e1::addLetter(i);
    for(int i=0;e2::s[i];i++) e2::addLetter(i);
//    DBG(e1::num);
//    DBG(e2::num);
    bild_Suffix_link();
//    dfs(2,""); NL;
    match(ss[2]);
    dfs2(0);
//    dfs(2,""); NL;
    int an = 0;
    for(int i=0;i<26;i++)
        if(e1::tree[1].next[i])
            an = max(an , ans(e1::tree[1].next[i] , 2));
    printf("%d",an);
}
