#include <stdio.h>
#include <string.h>

int dp[100005];
int coin[101];
int cnt[101];
int used[1000101];

int main()
{
    int t, n, k;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca++)
    {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &coin[i]);
        }
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cnt[j]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(used, 0, sizeof(used));
            for (int j = coin[i]; j <= k; j++)
            {
                if (!dp[j] && dp[j-coin[i]] && used[j-coin[i]] < cnt[i])
                {
                    ans++;
                    used[j]=used[j-coin[i]]+1;
                    dp[j] = 1;
                }
            }
        }
        printf("Case %d: %d\n", ca, ans);
    }
    return 0;
}
