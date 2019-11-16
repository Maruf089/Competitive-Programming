#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,temp=0,s=0,c=0,ans=-1;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
        {
            c++;
            if(temp>0)
                temp--;
        }
        else
        {
            temp++;
            if(temp>ans)
                ans=temp;
        }
    }
        cout<<ans+c;
}
