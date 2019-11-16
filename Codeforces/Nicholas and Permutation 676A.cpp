#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[1000];
    int n,i,j,c=0,count=0,mid,p,p1,m,m1;

    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];

        if(a[i] == 1)
            p=i;

        else if(a[i] == n)
            p1=i;
    }

    if(p1 > p)
    {
        p=p+1;
        p1=p1+1;
        m=p1-1;
        m1=n-p;
        int ans=max(m,m1);
        if(ans == 0)
            cout<<n<<endl;
        else
            cout<<ans<<endl;
    }
     else if(p1 < p)
    {
        p=p+1;
        p1=p1+1;
        m=p-1;
        m1=n-p1;
        int ans=max(m,m1);
        if(ans == 0)
            cout<<n<<endl;
        else
            cout<<ans<<endl;
    }
}
