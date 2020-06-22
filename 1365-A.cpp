


#include <bits/stdc++.h>
using namespace std;
#define ln '\n'

#define pb push_back
#define F first
#define S second
#define sz size()

#define ln '\n'
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define sf scanf
#define pf printf
#define ll long long
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */

//using namespace __gnu_pbds;
/*
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;

*/


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


using namespace std;

ll n,m,a,b,i,j,d,t,cs=0,counT=0,k;

int main()
{

    t = 1 ;
    cin >> t ;
    while(t--)
    {
        cin >> n >> m ;
        ll arr[n+9][m+8];
        set<ll>st,st1;
        counT = 0 ;
        f1(i,n)
        {
            counT = 0 ;
            f1(j,m)
            {
                cin >> arr[i][j];

                if(arr[i][j]==0)
                    counT++;
            }
            if(counT==m)
                st.insert(i);
        }

        f1(i,m)
        {
            counT= 0 ;
            f1(j,n)
                if(arr[j][i]==0)
                    counT++;
            if(counT==n)
                st1.insert(i);
        }

        k  = min(st.sz,st1.sz) ;
        if(k&1)
            cout << "Ashish\n";
        else
            cout << "Vivek\n";
    }
}
