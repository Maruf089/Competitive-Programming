#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,sum=0;
    cin>>n>>m;
    sum=n;
    while(n>=m)
    {

        sum+=n/m;
        n=n/m+n%m;
    }
        cout<<sum;
}
