#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,s=0,c=0;
    string a;

    getline(cin,a);
    for(i=0;i<a.size();i++)
    {
        if(a[i]=='1')
        {
            c++;
            break;
        }
    }
    for(n=i+1;n<a.size();n++)
    {
        if(a[n]=='1')c++;
        else
            s++;
    }
    if(c>=1 && s>=6)
        cout<<"yes";
    else
        cout<<"no";
}
