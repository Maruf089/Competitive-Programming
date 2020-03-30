/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)

long n,m,a,b,i,j,d,cs=0,counT=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;
int main()
{
    int t;
    cin >> t ;
    while(t--)
    {

        cin >> a >> b ;
       long d = abs(a-b);
   //  cout << d << ln;
        if(a<b)
        {
        d = b-a;
           if(d&1)
                cout << 1 << ln ;
            else
                cout << 2 << ln;
        }
        else if(a>b)
        {
            d = a-b;
            if(d%2==0)
                cout << 1 << ln ;
            else
                cout << 2 << ln;
        }
        else
            cout << 0 << ln ;
    }




    /// Comment the debugger section
}


