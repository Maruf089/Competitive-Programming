#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define F first
#define S second
#define d(x) cerr << #x << " = " << x << endl;
#define d2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define d3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define d4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

using namespace std;

const int N = 2e5 + 123;
pair < LL , int > low[N],up[N];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    freopen("error.txt", "w",stderr);
    #endif // ONLINE_JUDGE
    int n;
    LL m;
    scanf("%d%lld",&n,&m);
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n ; ++ i) {
        LL a; int l;
        scanf("%lld%d",&a,&l);
        if (l == 1)
            low[++c1] = mp(a,i);
        else
            up[++c2] = mp(a,i);
    }
    sort(low+1,low+1+c1);
    sort(up+1,up+1+c2);
    int i = c1, j = c2;
    while (m > 0) {
        if (i == 0) {
            m -= up[j].F;
            --j;
            continue;
        }
        if (j == 0) {
            m -= low[i].F;
            --i;
            continue;
        }
        if (low[i].F >= up[j].F)
            m -= low[i].F, -- i;
        else
            m -= up[j].F, -- j;
    }

    while (m <= 0 && i > 0 && j < c2 && m-low[i].F+up[j+1].F <= 0)
            m = m - low[i].F + up[j+1].F,
            --i,
            ++j;
    printf("%d %d\n",c1-i+c2-j,c1-i);
    for (int k = i + 1 ; k <= c1 ; ++ k) printf("%d ",low[k].S);
    for (int k = j + 1 ; k <= c2 ; ++ k) printf("%d ",up[k].S);
    return 0;
}
