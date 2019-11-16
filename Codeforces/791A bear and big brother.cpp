#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c=0,l,i,bob;
    cin>>a>>b;
    l=a;
    bob=b;
    for(i=1;i<=b;i++)
    {
        l=l*3;
        bob*=2;
        if(l>bob)
        {
            cout<<i;
            return 0;
        }
    }

}
