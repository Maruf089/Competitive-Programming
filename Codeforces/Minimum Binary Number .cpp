#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,c=0,n;
    cin>>n;

    string s;
    cin>>s;
    if(s[0]=='0')
    {
        cout<<0;
        return 0;
    }
    cout<<1;

    for( j =0; j<n; j++)
    {
        if(s[j]=='0')
            cout<<"0";
    }

}
