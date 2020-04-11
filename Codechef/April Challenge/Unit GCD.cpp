
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,i,j,counT = 0,counT1,n ;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n<=3)
        {
            printf("1\n1");
            for(i=1; i<=n; i++)
            {
                printf(" %lld",i);
            }
        }
        else if(n==4)
            printf("2\n3 1 3 4\n1 2");
        else
        {
            counT = 1 + (n-3)/2;
            if((n-3)&1)
                counT += 1;

            printf("%lld\n3 1 2 3",counT);
            for(i=4; i<=n; i++)
            {
                if(i%2==0 and i!=n)
                {
                    printf("\n2 %lld %lld",i,i+1);
                    i++;
                }
                else if(i=n)
                {
                    printf("\n1 %lld",i);
                }

            }

        }
        printf("\n");
    }
}


