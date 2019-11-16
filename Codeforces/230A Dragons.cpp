#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,n,sum=0,r=0,i,j;
    int b[100000];
    pair<int,int>a[100001];

    cin>>s>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i].first;
        cin>>a[i].second;
    }
    sort(a,a+n);
   sum+=s;
    for(i=0;i<n;i++)
    {
        if(a[i].first<sum)
            sum+=a[i].second;
        else
          {
              cout<<"NO"<<endl;
              return 0;
          }
    }
        cout<<"YES";
}
