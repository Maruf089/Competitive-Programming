#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c=0,i,d,c1,l;
    string s;
    cin>>s;
    l=s.length();

    for(i=0;i<l;i++)
    {
        if(s[i]>='A' && s[i]<='Z')c++;
    }

    if(c==l || (c==l-1 && s[0]>='a' && s[0]<='z'))
       {
           for(i=0;i<l;i++)
            {
                if(s[i]<'a')
                    s[i]+=32;
                else
                    s[i]-=32;
            }
       }
        cout<<s;

}
