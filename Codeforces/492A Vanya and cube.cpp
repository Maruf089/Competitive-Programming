#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,Count=0,s=0,sum=0,n;
cin>>n;
    for(i=1;;i++){
        sum=sum+i;
        s=s+sum;
        if(s>n){break;}
        Count++;
    }
    cout<<Count;
    return 0;
}
