#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,s=0,p=0,count=0;
    int a[1000001];

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];

        if(a[i]<0)
            p=i;

    }
    for(i=0; i<=p; i++)
    {
        if(a[i] > 0)
            s+=a[i];
        else
        {
            if(s==0)
                count++;
           if(s>0)s--;
        }

    }
    cout<<count;
}
