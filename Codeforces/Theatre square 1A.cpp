#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main()
{
    double t,s,m,n,a;

    cin>>m>>n>>a;

    t=ceil(m/a);
    s=ceil(n/a);

  printf("%.0lf",t*s);

}

