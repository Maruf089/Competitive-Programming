#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,sum=0,j,s=0,c=0;
    float r;

    cin>>n;
    int a[n];

    for(i=0;i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    r=(float)sum/2;

sort(a,a+n);


    for(j=n-1; j>=0; j--)
    {
        s+=a[j];
        c++;

        if(s>r)
        {
            cout<<c;
            return 0;
        }
    }
}
