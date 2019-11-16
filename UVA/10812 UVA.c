#include<stdio.h>
int main()
{
    int s,d,divide,sum,i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&s,&d);
        if(s<d)
        {
            printf("impossible\n");
            continue;
        }
        sum=(s-d)/2;
        divide=s-sum;
        printf("%d %d\n",divide,sum);
    }
}
