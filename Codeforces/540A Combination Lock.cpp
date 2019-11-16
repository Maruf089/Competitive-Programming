#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,c=0,t1,t2;

    cin>>n;
    char a[n],b[n];

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
        cin>>b[i];

    for(i=0;i<n;i++)
    {
        t1=abs(a[i]-b[i]);
        t2=10-t1;

        if(t1>t2)c+=t2;

        else
            c+=t1;
    }
    cout<<c;
}
