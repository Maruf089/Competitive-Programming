#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,count=1,c=0,n;
    cin>>n;
    string s;
    cin>>s;

    for(i=1; i<s.size(); i++)
    {
        if(s[i]=='x' && s[i-1]=='x')
        {
            count++;
            if(count>2)
            {
                c++;
            }

        }
        else
            count=1;
    }
    cout<<c;
}

