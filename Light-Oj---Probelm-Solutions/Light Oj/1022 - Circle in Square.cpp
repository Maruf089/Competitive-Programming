
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    double r;
    double sarea,carea,area;
    int t;

    cin>>t;

    for (int i = 1; i <= t; i++)
    {
        cin>>r;

        carea = 2 * acos(0.0) * r * r;
        sarea = (2 * r) * (2 * r);
        area = sarea - carea;

        printf("Case %d: %.2lf\n",i, area);
    }


}
