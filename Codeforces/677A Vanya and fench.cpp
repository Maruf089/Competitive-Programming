#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,h,i,sum=0;
    cin>>n>>h;
    int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];

        if(a[i]>h)sum+=2;

        else
            sum+=1;
    }
    cout<<sum;

    return 0;
}
