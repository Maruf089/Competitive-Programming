#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,sum=0,l,l1,j,k,h,Swap,s,t=0;
    int a[500],m[500];
    cin>>n;
    cin>>l;
for(i=0;i<l;i++)
{
    cin>>a[i];
    k=a[i];
   m[k]=1;
}
cin>>l1;
for(i=0;i<l1;i++)
{
    cin>>a[i];
    k=a[i];
    m[k]=1;
}

for(k=1;k<=n;k++)
{
    if(m[k]!=1)
    {
        cout<<"Oh, my keyboard!";
        return 0;
    }
}
cout<<"I become the guy.";

}
