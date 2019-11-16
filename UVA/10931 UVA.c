#include<stdio.h>
int main()
{
    int n,sum=0,d,i=0,j,q;
    long long int s,result;
    int a[1000];
    while(scanf("%d",&n) && n!=0)
    {
        sum=0,i=1;
        q=n;
        while(q!=0)
        {
            sum+=q%2;
            a[i++]=q%2;
            q=q/2;
        }
    printf("The parity of ");

    for(j=i-1;j>0;j--)
    {
    printf("%d",a[j]);
    }

    printf(" is %d (mod 2)\n",sum);
    }
    return 0;
}
