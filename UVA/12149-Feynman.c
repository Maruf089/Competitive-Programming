#include<stdio.h>
int main()
{
    int i,n,sum;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        else
        {sum=0;
        for(i=1;i<=n;i++)
        {
            sum=sum+(i*i);
        }
        printf("%d\n",sum);}
    }
    return 0;
}
