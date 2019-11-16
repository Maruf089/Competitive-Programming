#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c=0,i;
    char j;
    cin>>n;
    char a[n];

    cin>>a;

    for(int i=0;i<n;i++)
    {
        if(a[i]>='A' && a[i]<='Z')
            a[i]=a[i]+32;
    }

    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(a[i]!=a[i+1])c++;
    }

    if(c==26)
        cout<<"YES";
    else
        cout<<"NO";
}
