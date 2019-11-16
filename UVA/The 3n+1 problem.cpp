#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,m,n,i,j,p=0,high=0;;
    while(scanf("%lld %lld",&a,&b)!=EOF){
    m=b;
    n=a;
    if(m<n)
        {
            m=a;
            n=b;
        }
    high = 0;
    for(i=m;i>=n;i--)
    {
        for(j=i;j>=1;j--)
        {
            start:

            if(j==1)
               {
                   p++;
                   break;
               }

            else if(j%2==0)
            {
                j/=2;

                p++;
                goto start;
            }
            else if(j%2!=0)
            {
                j=3*j+1;
                p++;
                goto start;
            }

        }
            if(high<p)
                high=p;
            p=0;
    }
    cout<<a<<" "<<b<<" "<<high<<endl;
    }


}
