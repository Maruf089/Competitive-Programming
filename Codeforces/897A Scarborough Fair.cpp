#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,l,r,i,j;
    char c1,c2;
    string a;
    cin>>n>>m;

    cin>>a;

    for(i=0;i<m;i++)
    {
        cin>>l>>r>>c1>>c2;

        for(j=l-1;j<r;j++)
        {
            if(a[j]==c1)
            {
                a[j]=c2;
            }
        }
    }
        cout<<a;
}
