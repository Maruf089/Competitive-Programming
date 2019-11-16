
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, a, b;
    cin>>n;
    long sum=0;

    for(int i = 1; i <= n; i++)
    {
        sum = 0;
        cin>> a >> b;

        sum += 4*abs(a-b)+3+5+3;
        sum += a*4+3+5;

        printf("Case %d: %ld\n",i,sum);

    }
}
