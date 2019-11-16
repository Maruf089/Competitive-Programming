#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        if((a[0]%2==0 && a[1]%2==0) || (a[0]%2==0 && a[2]%2==0) || (a[1]%2==0 && a[2]%2==0))
        {
            if(a[i]%2!=0)
            {
                cout<<i+1;
            return 0;
            }
        }

        if((a[0]%2!=0 && a[1]%2!=0) || (a[0]%2!=0 && a[i+2]%2!=0)|| (a[1]%2!=0 && a[2]%2!=0))
        {
            if(a[i]%2==0)
            {
                cout<<i+1;
            return 0;
            }
        }
    }

}
