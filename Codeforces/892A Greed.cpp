#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,i,j,sum=0,ans=0,c=0;

    cin>>n;
    long long int a[n],b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
     for(i=0;i<n;i++)
     {
         cin>>b[i];
     }
     sort(b,b+n);

     if((b[n-1]+b[n-2])>=sum)
        cout<<"YES";
     else
        cout<<"NO";

}
