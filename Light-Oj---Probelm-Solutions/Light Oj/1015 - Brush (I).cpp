
#include <stdio.h>
int main()
{
        int T,N,d=0,i,j,dust;
        scanf("%d\n",&T);
        for(i=1;i<=T;i++){
            scanf("%d\n",&N);
            d=0;
            for(j=1;j<=N;j++){
                scanf("%d",&dust);
                if(dust>0)
                    d=d+dust;
            }printf("Case %d: %d\n",i,d);
        }

        return 0;
        }
