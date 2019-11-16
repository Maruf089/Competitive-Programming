#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z,ans=0;
    cin>>x>>y>>z;

    if((y<x && x<z) || (x<y && x>z))
    {
        ans=abs(x-y)+abs(x-z);
    }
    else if((x<y && y<z) || (y>z && x>y))
    {
        ans=abs(x-y)+abs(y-z);
    }
    else
        ans=abs(z-y)+abs(x-z);

    cout<<ans;
}
