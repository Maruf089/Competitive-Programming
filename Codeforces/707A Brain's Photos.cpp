#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,j,i,c=0,s=0;
    cin>>n>>t;
    char ch;

    for(i=0;i<n;i++)
    {
        for(j=0;j<t;j++)
        {
        cin>>ch;

        if(ch=='W' || ch=='B' || ch=='G')c++;

        else
            s++;
        }

    }

    if(s>=1)
    {
        cout<<"#Color";
    }
    else
        cout<<"#Black&White";
}
