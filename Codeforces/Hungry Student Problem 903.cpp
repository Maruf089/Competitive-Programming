
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,s;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>s;
        if(s<=11)
        {
            if(s%3==0 || s==7 || s==10)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }


}
