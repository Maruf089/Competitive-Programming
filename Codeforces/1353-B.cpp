#include <bits/stdc++.h>
using namespace std;
#define ln '\n'


#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define MOD 1000000007
#define PI acos(-1)
#define ll long long int

#define sz size()
#define LCM(a,b) (a*(b/__gcd(a,b)))
//#define harmonic(n) 0.57721566490153286060651209+log(n)+1.0/(2*n)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))
ll n,m,a,b,t,i,j,d,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
int main()
{
    cin >> t ;
    while(t--)
    {
        cin >> n >> k ;
        vector<ll>vc,vc1;
        f0(i,n)
        {
            cin >> a ;
            vc.push_back(a);
        }
        sort(all(vc));
        f0(i,n)
        {
            cin >> a ;
            vc1.push_back(a);
        }
        sort(all(vc1));reverse(all(vc1));
        sum = 0 ;
        f0(i,n)
        {
            if(vc1[i]>=vc[i] and k)
            {
                sum += vc1[i];
                k--;
            }
            else
                sum += vc[i];
        }
        cout << sum << ln ;
    }
}
