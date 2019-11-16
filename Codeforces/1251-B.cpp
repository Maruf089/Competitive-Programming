#include<bits/stdc++.h>
using namespace std;
#define ln '\n'

#define inp(x) scanf("%lld",&x)
#define D(x) cout<< #x " = "<<x<<endl
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f(a,b) for(int i=a;i<=(b);i++)
#define _case cout<<"Case "<<++cs<<": "



#define PI acos(-1)
#define ll long long int
#define ull unsigned long long
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
#define vi vector <int>
#define vll vector <ll>
#define vs vector <string>
#define pb push_back
#define eb emplace_back
#define mpii map <int,int>
#define mpsi map <string,int>
#define mpll map <long long,long long>
#define MP make_pair
#define F first
#define S second
#define B begin()
#define E end()
#define sz size()
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b)))
//#define harmonic(n) 0.57721566490153286l+log(n)


ll n,m,a,b,i,j,d,t=1,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;



int main()
{

    cin >> t;
    while(t--)
    {
        cin >> n ;
        vector<ll>vc;
        ll zero = 0,one=0;
        while(n--)
        {
            string s,s1;
            cin >> s;
            l = s.sz;
            vc.pb(l);
      //      sort(s.begin(),s.end());
          //  ll one =0,zero=0;
            f0(i,l)
            {
                if(s[i]=='0')
                    zero++;
                else
                    one++;
            }
        }
        counT=0;
        sort(vc.rbegin(),vc.rend());
        f0(i,vc.sz)
        {
            if(vc[i]&1 and one>=0 and zero>=0)
            {
                if(one<=zero and one)
                {
                    if(zero>=vc[i]-1)
                    {
                        zero-=vc[i]-1;
                        one--;
                        counT++;
                    }
                }
                else if(one>=zero and zero)
                {
                    if(one>=vc[i]-1)
                    {
                        one-=vc[i]-1;
                        zero--;
                        counT++;
                    }
                }
                 else if(one<=zero and !one)
                {
                    if(zero>=vc[i])
                    {
                        zero-=vc[i];
                        counT++;
                    }
                }
                else if(one>=zero and !zero)
                {
                    if(one>=vc[i])
                    {
                        one-=vc[i];
                        counT++;
                    }
                }
            }
            else if(vc[i]%2==0 and (one>=0 or zero>=0))
            {
                if(vc[i]<=one)
                {
                    counT++;
                    one-=vc[i];
                }
                else if(vc[i]<=zero)
                {
                    counT++;
                    zero-=vc[i];
                }
                else if(vc[i]<=(one+zero))
                {
                    if(one>=2 and zero>=2)
                    {
                        counT++;
                        if(one<=zero)
                        {
                            one-=2;
                            zero -= vc[i]-2;
                        }
                        else if(zero<=one)
                        {
                            zero-=2;
                            one -= vc[i]-2;
                        }
                    }
                }

            }
        }
   // D(counT);
   cout << counT << ln ;
    }

}

