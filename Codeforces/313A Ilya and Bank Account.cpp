#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int r2,n,r,i,temp,j,Max;
    static int r1;
    cin>>n;
    if(n>0)
    {
        cout<<n;
        return 0;
    }
    temp=n;

    if(n==(-10) || n==(-20) || n==(-30) || n==(-40) || n==(-50) || n==(-60) || n==(-70) || n==(-80) || n==(-90))
    {
        cout<<"0";
        return 0;
    }

    r1=n%10;
    for(i=1; i<=2; i++)
    {
        r=temp%10;
        temp/=10;
    }
    r2=r;

     if(r1<r2)
     cout<<n/10;
     else
        cout<<temp*10+r1;



}
