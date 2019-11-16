#include<bits/stdc++.h>
using namespace std;
int ret(string s,int n)
{
    for(int i = 0; i < (n-1); ++i)
        if(s[i] == '1' && s[i+1] == '1')
            return 0;
    return 1;

}
int main()
{
    int a,b,cs=0,i,j,n;
    cin>>n;
    string s;
    cin>>s;
    if(ret(s,n)==0)
    {
        cout<<"No";
        return 0;
    }
    for(i=0; i<n; i++)
        if(s[i]=='0')
        {
            s[i]='1';
            if(ret(s,n))
            {
                cout<<"No";
                return 0;
            }
            s[i]='0';
        }
    cout<<"Yes";

}
