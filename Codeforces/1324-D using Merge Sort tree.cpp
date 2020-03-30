#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 200005;
vector<int> sTree[MAX];
int a[MAX],b[MAX];
vector<int>tree[5*MAX];

void build_tree( int cur, int l, int r )
{
    if( l==r )
    {
        tree[cur].push_back( a[ l ] );
        return ;
    }
    int mid = (l+r)/2,x=2*cur;
    build_tree(x, l, mid);
    build_tree(x+1,mid+1,r);
    merge(tree[x].begin(),tree[x].end(),tree[x+1].begin(),tree[x+1].end(),back_inserter(tree[cur]));
}
int query( int cur, int l, int r, int x, int y, int k)
{
    if( r < x || l > y )
    {
        return 0;
    }
    if( x<=l && r<=y )
    {
        return tree[cur].end() - upper_bound(tree[cur].begin(),tree[cur].end(),k);
    }
    int mid=l+(r-l)/2;
    return query(2*cur,l,mid,x,y,k)+query(2*cur+1,mid+1,r,x,y,k);
}
int main()
{
    ll ans=0;
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
        cin>>b[i];
    for(int i=1; i<=n; i++)
    {
        a[i]=a[i]-b[i];
        b[i]=-a[i];
    }
//        for(int i=1; i<=n; i++)
//        cout << b[i] << ' ';
//        cout << endl;

    build_tree(1,1, n);
    for(int i=2; i<=n; i++)
    {

        int y=query(1,1,n,1,i-1,b[i]);
        ans+=y;
    }
    cout<<ans<<endl;



}
