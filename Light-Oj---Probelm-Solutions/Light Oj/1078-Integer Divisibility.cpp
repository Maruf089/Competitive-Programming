/**Bismillahir Rahmanir Rahim.**/

#include<bits/stdc++.h>
#define endl '\n'
#define sf scanf
#define pf printf
#define NL printf("\n")
#define SP printf(" ")


#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout)

string s,s1;
long long n,m,r,i,j,d,t,cs=0,counT=1,ans=0,l=0,temp=0,sum=0,Max,Min,num;
int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n>>m;
        r=l=0;
        for(j=0;j<n;j++)
        {
            r=(r*10+m)%n;
            l++;
            if(r==0)
                break;
        }
        printf("Case %lld: %lld\n",i,l);
    }
}

