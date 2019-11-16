#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i,j;
    cin>>n>>t;
    string a;
    cin>>a;

    for(i=0;i<t;i++)
    {
        for(j=1;j<n;)
        {
            if(a[j]=='G' && a[j-1]=='B')
            {
                a[j]='B';
                a[j-1]='G';
                j+=2;
            }
            else
                j++;
        }
    }
    cout<<a;

    return 0;
}
