#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,r,c=0,i;

    cin>>k>>r;

    for(i=1; ;i++)
    {
        if((k*i)%10==0 || (k*i)%10==r)
        {
            cout<<i;
            return 0;
        }
    }
}
