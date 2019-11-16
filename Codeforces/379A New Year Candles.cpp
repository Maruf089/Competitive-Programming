#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,ans=1,sum=0;
    cin>>a>>b;
    sum=a;
    ans=a/b;
    while(ans!=0)
    {
        sum+=ans;
        ans=ans/b;
    }
    cout<<sum;
}
