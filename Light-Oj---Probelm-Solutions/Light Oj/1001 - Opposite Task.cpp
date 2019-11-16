
#include<stdio.h>
int main()
{
    int a,b,n,j,i;
    scanf("%d",&j);
    for(i=1;i<=j;i++){
        scanf("%d",&n);
        a=n/2;
        b=n-a;
        printf("%d %d\n",a,b);
    }

}
