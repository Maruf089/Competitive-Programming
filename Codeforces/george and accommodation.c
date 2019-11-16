#include<stdio.h>
int main()
{
    int n,pi,qi,i;
    scanf("%d",&n);
    i=0;
    while(n--){
    scanf("%d %d",&pi,&qi);
        if((qi-pi)>=2){
            i++;
        }
    }
    printf("%d",i);
    return 0;
}
