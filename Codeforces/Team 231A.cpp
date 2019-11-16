#include<iostream>
using namespace std;

int main()
{
    int t,i,j,a,b,c,Count=0;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if((a==1 && b==1) || (a==1 && c==1) || (b==1 && c==1)){Count++;}
    }
    cout<<Count<<endl;
}
