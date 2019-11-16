#include<stdio.h>
int main()
{
    int a,c=0,n,i;
    scanf("%d",&a);
    for(i=1;i<=a;i++){
        scanf("%d",&n);
        c=0;
        while(n){
            c=c+n%2;
            n/=2;
        }
        if(c%2==0){
            printf("Case %d: even",i);
        }
        else
            printf("Case %d: odd",i);
            printf("\n");
    }

    return 0;
}

