#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    string a="I love";
    string b="I hate";
    string c=" that";
    string d=" it";

    cin>>n;
    if(n==1)
    {
        cout<<"I hate it";
        return 0;
    }
    if(n!=1)
    {
      cout<<b;
    for(i=2; i<=n; i++)
    {
            cout<<c<<" ";

        if(i%2==0)
            cout<<a;

        else if(i%2!=0)
            cout<<b;

        if(i==n)
            cout<<d;

    }
    }
}
