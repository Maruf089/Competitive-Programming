#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,s,d,c=0,i;
    cin>>n;

    for(i=n/2;i>=1;i--)
    {
        if(__gcd(i,n-i)==1)
            {
            cout<<i<<" "<<n-i;
        break;
            }
    }

}
