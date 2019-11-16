#include<stdio.h>
#include<string.h>

int main()
{
    int n,max,i,j=0;
    int a[10000];
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%s",a);
        max=a[0];
        for(j=1;j<strlen(a);j++)
        {
            if(max<a[j])
            {
                max=a[j];
            }
        }
        printf("Case %d: %d\n",i,max);

    }
    return 0;
}
