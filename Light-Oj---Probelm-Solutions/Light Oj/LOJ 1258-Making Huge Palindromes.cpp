#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int ans[N];
int tree[N][26], idx ;
int len[N], link[N], t ;
int occurrence[N];
/// char s[N] ; /// 1-indexed
string s ;
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
        Max = max(Max,len[idx]);
        link[idx] = len[idx] == 1 ? 2 : tree[x][c];
        ans[idx] = 1 + ans[link[idx]];
    }
    t = tree[t][c];
}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        Init();
        Max = 0 ;

        cin >> s ;
        s = '#'+s;
        for(int j=1; j<s.size(); j++)
        {
            extend(j);
        }
        cout << "Case "<< i << ": " << (s.size()-1) + (s.size()-1) - Max << endl;
    }
}


/// Using KMP

/*

int prefix_table[1000005];

void make_table(string pattern)
{
    int sz,i,ind;
    sz=pattern.size();
    ind=0;
    for(i=1;i<sz;)
    {
        if(pattern[i]==pattern[ind])
        {
            prefix_table[i]=ind+1;
            ind++,i++;
        }
        else if(ind!=0)
            ind=prefix_table[ind-1];
        else
            prefix_table[i]=0,i++;
    }
}

int KMP(string st,string pattern)
{
    make_table(pattern);
    int i=0,j=0,n=st.size(),m=pattern.size();
    while(1)
    {
        if(i==n)
            return j;
        if(st[i]==pattern[j])
            i++,j++;
        else if(j!=0)
            j=prefix_table[j-1];
        else
            i++;
    }
    return j;
}

int main()
{
    string st,pattern;
    int t,id=0,sz,i,j,ans,fg=0;
    cin>>t;
    while(t--)
    {
        cin>>st;
        pattern=st;
        reverse(pattern.begin(),pattern.end());
        fg=2*st.size()-KMP(st,pattern);
        printf("Case %d: %d\n",++id,fg);
    }
    return 0;
}

/*
