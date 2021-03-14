
#include<bits/stdc++.h>
#define mx 200005
using namespace std;

int arr[mx+1],node[4*mx+1],pos[mx+1],ans[mx+1];
unordered_set <int> sett;



/// DEBUG --------------------------------------------------------------------------------->>>>>>

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


void build()
{
    memset(node,-1,sizeof node);
}

void update(int ind,int i,int j,int s,int e,int val)
{
    if(i>e || j<s)
        return;
    if(i>=s && j<=e)
    {
        node[ind]=val;
        return;
    }

    int mid=(i+j)>>1;
    if(node[ind]!=-1)
        node[ind<<1]=node[ind<<1|1]=node[ind];
    node[ind]=-1;
    update(ind<<1,i,mid,s,e,val);
    update(ind<<1|1,mid+1,j,s,e,val);
    if(node[ind<<1]==node[ind<<1|1])
        node[ind]=node[ind<<1];
}

void query(int ind,int i,int j)
{
    if(node[ind]!=-1)
    {
        sett.insert(node[ind]);
        return;
    }
    if(i==j)
        return;

    int mid=(i+j)>>1;

    query(ind<<1,i,mid);
    query(ind<<1|1,mid+1,j);
}

int main()
{
    int i,j,a,b,k=0,l,c=0,t,n,id=1;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        build();
        c=n;
        while(c--)
        {
            scanf("%d %d",&a,&b);
            update(1,1,2*n,a,b,k++);
        }
        query(1,1,2*n);
        printf("Case %d: %d\n",id++,sett.size());
        memset(node,0,sizeof node);
        memset(pos,0,sizeof pos);
        sett.clear();
    }
    return 0;
}
