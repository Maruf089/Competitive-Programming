#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,a,b,m=0,c=0;
    cin>>n;

    for(j=1;j<=n;j++)
    {
        cin>>a>>b;

        if(a>b)m++;
        else if(a<b)
            c++;
    }
    if(m>c)
        cout<<"Mishka";
        else if(m<c)
            cout<<"Chris";
        else
            cout<<"Friendship is magic!^^";
}
