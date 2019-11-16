#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i,j,s=0,c=0,t=0;
    cin>>n>>k;
    int a[n],b[n];
    if( k== 0)
    {
        cout<<0;
        return 0;
    }
    for( i=0; i<n; i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(a,a+n);
    for( i=0; i<n; i++)
    {
        s += a[i];
        if( s <= k)
            c++;
    }
    cout<<c<<endl;
    int temp = -1 ;
    for(i=0; i<c; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i]==b[j])
            {
                cout<<j+1<<" ";
                b[j]=-1;
                break;
            }
        }
    }
}

