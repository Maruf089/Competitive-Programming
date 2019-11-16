#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c=0,i,j,ans=0,d;
    string a;
    cin>>a;
    int l=a.length();
    sort(a.begin(),a.end());
    for(i=0;i<l;i++)
    {
        if(a[i]!=a[i+1])c++;
    }
    if(c%2==0)cout<<"CHAT WITH HER!";
    else
        cout<<"IGNORE HIM!";
}
