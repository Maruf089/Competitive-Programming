

#include<bits/stdc++.h>
using namespace std;

#define ln '\n'
#define f0(i,b) for(int i=0;i<(b);i++)
#define PI acos(-1)
#define ll long long int
#define pb push_back
#define sz size()
#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))


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


ll n,m,a,b,i,j,d,t,cs=0,counT=0;


int main()
{
    cin >> t ;

    while(t--)
    {
        cin >> n;

        vector<ll>vc,chk(n);

        f0(i,n)
        {
            cin >> a ;
            vc.pb(a);
        }

        int flag = 0,inc=0,dec = 0;
        int flag11 = 0;

        counT = n/2;

        f0(i,n)
        {
            if(inc<=counT)
            {
                chk[i] = inc;
                inc++;
            }
            else
            {

                for(j=n-1; j>=i; j--)
                {
                    chk[j] = dec;
                    dec++;
                }
                break;

            }
        }

  //      dbg(chk);


        for(i=0; i<n; i++)
        {

            if(vc[i]>=chk[i])
                continue;
            else
            {
                flag = 1;
                break;
            }

        }

        reverse(all(chk));
        for(i=0; i<n; i++)
        {

            if(vc[i]>=chk[i])
                continue;
            else
            {
                flag11 = 1;
                break;
            }

        }

//        dbg(flag11,flag);

        if(flag11==0 or flag==0)
        {
            cout << "Yes" << ln ;
        }
        else
            cout << "No" << ln ;

        vc.clear();
        chk.clear();

    }


}


