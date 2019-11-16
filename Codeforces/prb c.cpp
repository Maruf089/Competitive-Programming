#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    LL i,j,n,m,temp=0,sum = 0;
    cin>>n>>m;
    LL a[n],b[m];

    for(i=1; i<=n; i++)
        cin>>a[i];

    for(i=0; i<m; i++)
        cin>>b[i];

        sum += a[1];
          i = 1;
            for(j=0;j<m;j++)
            {

                if(b[j] <= sum )
                    cout<<i<<" "<<abs(temp-b[j])<<endl;
                else if( b[j] > sum )
                {
                   temp += a[i];
                  // cout<<" temp "<<temp<<endl;
                   i++;
                  // cout<<" I "<<i<<endl;
                  sum += a[i];
                  //cout<<" sum "<<sum<<endl;
                  j--;
                }
            }
}
