#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,c=0,temp=0;
    string s;
    cin>>s;

    for( i=0;i<s.size();i++)
    {
        if(s[i]=='-')
            c++;
        else
            temp++;
    }
    if(c==0 or temp==0)
        cout<<"YES"<<endl;
    else if( c%temp == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

