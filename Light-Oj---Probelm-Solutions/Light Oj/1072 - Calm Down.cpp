
#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;

int main()
{
    double r,R,s=0;
int i,t,n;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>R>>n;

        r = ( R * sin(pi/n))/(1+sin(pi/n));

        printf("Case %d: %.10lf\n",i,r);

    }
}
