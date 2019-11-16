#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int t,i,l;
    char s[100];
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>s;
        l=strlen(s);
        if(l<=10)
            cout<<s<<endl;
        else
        {
            cout<<s[0]<<l-2<<s[l-1]<<endl;
        }

    }
}
