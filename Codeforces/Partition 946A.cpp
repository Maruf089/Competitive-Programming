#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,j,i,s=0;

    cin>>n;

    int a[n],sum=0;

    for(i = 0 ; i < n; i++ )
    {
        cin>>a[i];

    if(a[i] >= 0)
        sum += a[i];
    else
        sum -= a[i];
    }
    cout<<sum<<endl;
}
