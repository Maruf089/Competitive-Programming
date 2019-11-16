#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define D(x) cout<< #x " = "<<x<<endl

#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 500000000
#define maxN 111
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define D(x) cout<< #x " = "<<x<<endl

int n, f[maxN * 2][maxN];

int main()
{
    int caseNo, cases = 0, val;
    scanf("%d", &caseNo);

    while (caseNo--) {
        scanf("%d", &n);

        FOR (i, 1, n)
            FOR (j, 1, i)
            {
                scanf("%d", &val);
                f[i][j] = 0;

                if (i != 1)
                {
                    if (j != 1)
                    {

                        f[i][j] = f[i - 1][j - 1];
               ///         D(f[i][j]);
                    }
                    if (j != i)
                    {

                        f[i][j] = max(f[i][j], f[i - 1][j]);
                 ///       D(f[i][j]);
                    }
                }
                f[i][j] += val;
             ///   cout<<"Last F ";
             ///   D(f[i][j]);
            }


               for (int i = n + 1, k = n - 1; i <= 2 *n+1; i++, k--)
            for (int j = 1; j <= k; j++) {
                scanf("%d", &val);
                f[i][j] = 0;
                f[i][j] = max(f[i - 1][j], f[i - 1][j + 1]);
           /// D(f[i][j]);
                f[i][j] += val;
           /// D(f[i][j]);
            }
        printf("Case %d: %d\n", ++cases, f[2*n - 1][1]);
    }

    }

