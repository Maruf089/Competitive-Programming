


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

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define Maximumn 1000005
typedef long long ll;

const double PI = acos(-1.0);
const ll mod = 1e9 + 7;

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

ll n,m,a,b,i,j,d,t,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Maximum,Min,num;



int main()
{
    t = 1 ;
    cin >> t ;

    while(t--)
    {
        cin >> n ;
        ll arr[n+9];

        f0(i,n)
        cin >> arr[i];

        counT = 0 ;

        f0(i,n)
        {
            cin >> a ;
            if(a==0)
                counT++;
        }

        ll one = n - counT ;

        ll zero = counT ;

        if(zero==n or one==n)
        {
            int flag = 0;

            f0(i,n-1)
            {
                if(arr[i]>arr[i+1])
                {
                    flag = 1 ;
                    break;
                }
            }
            if(flag==1)
                cout << "no\n";
            else
                cout << "yes\n";
        }
        else
        {
            cout << "yes\n";
        }
    }
}
