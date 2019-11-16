#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p=0,i,s,c=0,sum1=0,sum2=0;
    cin>>n;
    int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=0;i<n;i++)
    {
      if(a[i]<=a[i+1])
            c++;

        else
        {
            if(p<c)
                p=c;

            c=0;
        }
    }

    if(c>p+1)
        cout<<c;
    else
    cout<<p+1;

}
