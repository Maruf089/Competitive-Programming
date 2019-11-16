#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout)
string s,s1;
int main()
{
    long long n,m,a,b,i,j,counT=0,k,l=1,temp=0,sum=0,Max,Min,num;
    cin>>a>>b;
    if(a==b)
        cout<<1;
    else if(b-a>5)
        cout<<0;
    else
    {
        for(i=a+1; i<=b; i++)
        {
            l *= i%10;
            l%=10;
        }
        cout<<l;
    }



}


