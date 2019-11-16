#include<bits/stdc++.h>
#define endl '\n'

#define lp(loop,start,end) for(ll loop=start;loop<end;loop++)
#define lpd(loop,start,end) for(ll loop=end;loop>start;loop--)

#define PI acos(-1)
#define ll long long int
#define ull unsigned long long


#define mpii map <int,int>
#define mpsi map <string,int>
#define mpll map <long long,long long>

using namespace std;
string s,s1;
mpsi mp1;
int main()
{
    ll n,m,a,b,i,j,counT=0,k,l=0,temp=0,sum=0,Max,Min,num;

    cin>>n;
    lp(i,0,n)
    {
        cin>>s;
        mp1[s]++;
    }

    lp(i,0,n)
    {
        cin>>s;
        if(mp1[s])
          {
              mp1[s]--;
              counT++;
          }
    }
    cout<<n-counT;
}


