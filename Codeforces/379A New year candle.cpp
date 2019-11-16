#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,s,c,j,k;
    cin>>n>>p;
    int sum=n;

    up:
    k=n/p;

    //temp=n-k*p;cout<<temp<<endl;

    sum+=k;

    k+=n-k*p;

    if(k<p)
    {
        cout<<sum;
        return 0;
    }
    if(k>=p)
        n=k;
        goto up;


}
