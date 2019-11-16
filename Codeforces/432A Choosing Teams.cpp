#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,j,s=0,p=1,c=0;
    cin>>n>>k;
    int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    for(i=0;i<n;i++)
    {
        if(5-a[i]>=k)
            s++;
    }
        cout<<s/3;
}
