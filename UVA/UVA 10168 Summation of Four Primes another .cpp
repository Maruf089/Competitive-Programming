#include<stdio.h>
#include<string.h>
const int MAXN = 10000005;
int vis[MAXN], prime[700000], num;

void get_prime()
{
    num = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = vis[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(!vis[i])
        {
            prime[num++] = i;
            for(int j = i + i; j < MAXN; j += i)
                vis[j] = 1;
        }
    }
}

int main()
{
    int n;
    get_prime();
    while(~scanf("%d",&n))
    {
        if(n < 8)
        {
            printf("Impossible.\n");
            continue;
        }
        if(n&1)
        {
            printf("2 3 ");
            n -= 5;
        }
        else
        {
            printf("2 2 ");
            n -= 4;
        }
        for(int i = 0; i < num; i++)
            if(!vis[n-prime[i]])
            {
                printf("%d %d\n", prime[i], n-prime[i]);
                break;
            }
    }
    return 0;
}
