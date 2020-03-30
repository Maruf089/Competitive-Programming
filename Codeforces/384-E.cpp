#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair <int,int>

///**
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p )
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v )
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin() )
            os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v )
{
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v )
{
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if ( it != v.begin() )
            os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu ()
{
    cerr << endl;
}

template <typename T>
void faltu( T a[], int n )
{
    for (int i = 0; i < n; ++i)
        cerr << a[i] << ' ';
    cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}

/// TEMPLATE ----------------------------------------------------------------------->>>>>>



PII Time[200005];
ll tree[525000];
int num[200005],coeff[200005],fns = 1;
vector<int>edges[200005];

void dfs(int s,int k)
{
    if(coeff[s]!=0)
        return;
    coeff[s] = k ;
    Time[s].first = fns;
// dbg(s,Time[s].first);
    int i,t;
    for( auto u : edges[s])
    {
        dfs(u,-k); /// even->odd->even
    }
    Time[s].second = fns;
// dbg(s,Time[s].second);
    fns++;

}

void propagate(int pos)
{
    tree[2*pos] += tree[pos];
    tree[2*pos+1] += tree[pos];
    tree[pos] = 0;
}

void update (int pos,int L,int R,int l,int r,int val)
{
    if (L>r || l>R)
        return;
    if (L>=l && R<=r)
    {
        tree[pos]+=val;
        return;
    }

    if (tree[pos]!=0)
        propagate(pos);

    int x=pos*2,mid=(L+R)/2;
    update (x,L,mid,l,r,val);
    update (x+1,mid+1,R,l,r,val);
}

ll query (int pos,int L,int R,int k)
{
    if (L>k || k>R)
        return 0;
    if (L==R)
        return tree[pos];

    if (tree[pos]!=0)
        propagate(pos);

    int x=pos*2,mid=(L+R)/2;
    ll y=query(x,L,mid,k);
    ll z=query(x+1,mid+1,R,k);
    return y+z;
}

int main()
{
    int i,j,u,v,c,n,m;
    ll ans ;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%d",&num[i]);
    for(i=1; i<n; i++)
    {
        scanf("%d %d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,1);
    for(i=0; i<m; i++)
    {
        scanf("%d",&j);
        if(j==1)
        {
            scanf("%d %d",&u,&v);
            update(1,1,n,Time[u].first,Time[u].second,v*coeff[u]);
        }
        else
        {
            scanf("%d",&u);
            ans = query(1,1,n,Time[u].second);
            ans = (ans*coeff[u])+num[u];
            printf("%lld\n",ans);
        }
    }
}
