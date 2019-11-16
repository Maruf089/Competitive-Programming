#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,c=0;
    char a[8][8];
    for(j=0;j<8;j++)
    {
    for(i=0;i<8;i++)
    {
        cin>>a[i][j];
    }
    }
    for(j=0;j<8;j++)
    {
    for(i=0;i<8;i++)
    {
        if(i!=7)
        {
        if(a[i][j]==a[i+1][j])
            {
                cout<<"NO";
                return 0;
            }
        }

        if((i+2)<=6)
        {
        if(a[i][j]!=a[i+2][j])
        {
            c++;
        }
        }
    }
    }
    if(c==0)
    cout<<"YES";
    else
        cout<<"NO";
}
