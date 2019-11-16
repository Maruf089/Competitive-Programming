#include<stdio.h>
int main()
{
    int i,count=0,s=0,sum=0,n;
    scanf("%d",&n);
    for(i=1;;i++){
        sum=sum+i;
        s=s+sum;
        if(s>n){break;}
        count++;
    }
    printf("%d\n",count);
    return 0;
}
