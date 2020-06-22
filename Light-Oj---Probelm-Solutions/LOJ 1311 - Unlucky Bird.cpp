#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)

#define pf1(a) printf("%lld\n",a)
#define pf2(a,b) printf("%lld %lld\n",a,b)

int main()
{
    ll tc, t = 1;

    //freopen ("input.txt", "r", stdin);

    sc1(tc);

    while (tc--){

        double v1,v2,v3,a1,a2;
        cin >> v1 >> v2 >> v3 >> a1 >> a2;

        double t1 = v1 / a1;
        double t2 = v2 / a2;

        double s1 = 0.5 * a1 * t1 * t1;
        double s2 = 0.5 * a2 * t2 * t2;

        double t3 = max(t1, t2);

        double s = s1 + s2;
        double ss = t3 * v3;

        printf("Case %lld: %lf %lf\n", t++, s, ss);

    }

    return 0;
}
