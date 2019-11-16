#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,u=0,l=0,e=0,i;
    string a;
    cin>>a;
    for(i=0;i<a.size();i++)
    {
        if(a[i]>='A' && a[i]<='Z')u++;
        else if(a[i]>='a' && a[i]<='z')l++;
    }
    if(u<l || u==l)
    {
        for(i=0;i<a.size();i++)
        {
            if(a[i]>='A' && a[i]<='Z')
                a[i]=a[i]+32;
        }
    }
    else if(u>l)
    {
        for(i=0;i<a.size();i++)
        {
            if(a[i]>='a' && a[i]<='z')
                a[i]=a[i]-32;
        }
    }
    cout<<a;
}
