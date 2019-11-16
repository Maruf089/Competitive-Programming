#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,sum=0,i,p=0,ans = 1000;
    int a[10001];

    cin>>m>>n;

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);

    for(i=1; i<=m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if( a[j] == i )
                p++;
        }
        if( p < ans )
        {
            ans = p ;
        }
        p = 0;
    }

    cout<<ans<<endl;

}

