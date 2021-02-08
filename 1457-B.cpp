#include <bits/stdc++.h>
using namespace std;
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define ll long long int
ll n,m,t,i,j,d,k,ans=0,Max;
int main()
{
    cin >> t ;
    while(t--)
    {
        cin >> n >> k;
        vector<ll>vc[103];
        ll arr[n+9];
        f0(i,n)
        { cin >> arr[i] ;vc[arr[i]].push_back(i+1); }
        ans = LLONG_MAX;
        f1(i,100)
        {    Max = 0 ;
            if(vc[i].size())
            {
                f0(j,n)
                {
                    if(arr[j]!=i)
                    { Max++;j += k ;j--;}
                }
            }
          if(Max!=0)ans=min(ans,Max);
        }
        if(ans==LLONG_MAX) ans = 0;
        cout <<ans<<endl;
    }
}

