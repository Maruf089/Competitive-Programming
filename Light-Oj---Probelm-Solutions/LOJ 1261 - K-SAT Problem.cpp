#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false)
#define bfast cin.tie(0)
#define outs(x) cout << x << " "
#define outn(x) cout << x << "\n"
#define sf scanf
#define pf printf
#define nl puts("")
//#define i64 long long
#define high 50

typedef long long LL;
typedef vector<int>vii;
typedef vector<LL>vll;
typedef map<int, bool>mpbi;

int ar[high][high];

int main()
{
    fast;
    int n , m , k , t , tc=0 , i , j , p , x , tmp;
    mpbi mp;
    cin >> t;
    while(t--)
    {
        //cout << n << " " << m << " " << k;
        mp.clear();
        cin >> n >> m >> k;

        for(i=0; i<n; i++)
            for(j=0; j<k; j++)
                cin >> ar[i][j];

        cin >> p;
        while(p--)
        {
            cin >> x;
            mp[x] = true;
        }

        bool f=false, fl=true;

        for(i=0; i<n; i++)
        {
            f=false;

            for(j=0; j<k; j++)
            {
                if(ar[i][j] > 0 and mp[ar[i][j]])
                    f=true;

                if(ar[i][j] < 0)
                {
                    tmp = -ar[i][j];
                    if(!mp[tmp])
                        f=true;
                }
            }

            if(!f)
                fl=false;
        }

        cout << "Case " << ++tc << ": ";

        if(fl)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
