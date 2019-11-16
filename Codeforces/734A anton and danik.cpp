#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,s=0,c=0,i,j;
    string a;
    cin>>n;
    cin>>a;
    for(i=0;i<a.size();i++)
    {
        if(a[i]=='A')s++;
        else if(a[i]=='D')c++;
    }
    if(s>c)
        cout<<"Anton";
    else if(c>s)
        cout<<"Danik";
    else
        cout<<"Friendship";
}
