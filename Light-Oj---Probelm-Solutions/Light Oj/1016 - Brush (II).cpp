
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long  int c,n,w,t,p=0,j,s=1;
    long long int a[50000];
    float d;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        s=1;

        cin>>n>>w;

        for(j=0;j<n;j++)
        {
            cin>>c;
            cin>>a[j];

        }
        sort(a,a+n);

        p=a[0];
        p+=w;

         for(j=0;j<n;j++)
         {
             if(a[j]>p)
                {

                   s++;
                   p=w+a[j];
                }
         }
         cout<<"Case "<<i<<": "<<s<<endl;
    }
}
