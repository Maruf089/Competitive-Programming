#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,x,y,d=0,c=0;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        if(x>0)
            c++;
        else
            d++;
    }
    if(c<=1 || d<=1)
        cout<<"Yes";
    else
        cout<<"No";
}
