#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[4];
    long long i,j,c=0;
    for(i=0;i<4;i++)
        cin>>a[i];
    sort(a,a+4);

    for(i=0;i<4;i++)
    {
        if(a[i]!=a[i+1])c++;
    }
    cout<<4-c;
}
