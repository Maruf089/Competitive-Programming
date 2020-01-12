#include <bits/stdc++.h>

using namespace std;

vector<int> ara[101];


void primeFactor()
{
    for(int j=2; j<=100; j++)
    {
        int tmp = j;
        while(tmp%2==0)
        {
            tmp/=2;
            ara[j].push_back(2);
        }
        int limit = sqrt(tmp+1);
        for(int i=3; i<=limit && tmp>1; i+=2)
            while(tmp%i==0)
            {
                tmp/=i;
                ara[j].push_back(i);
            }
        if(tmp > 2) ara[j].push_back(tmp);
    }
}
int main()
{
    primeFactor();
    int tst, n;
    scanf("%d", &tst);
    for(int i=1; i<=tst; i++)
    {
        scanf("%d", &n);
        int ans[103];
        memset(ans, 0, sizeof(ans));
        for(int k=2; k<=n; k++)
            for(int l=0; l<ara[k].size(); l++)
                ans[ara[k][l]]++;
        for(int j=2, first=1; j<=100; j++)
            if(ans[j]>0)
            {
                if(first==1)
                {
                    printf("Case %d: %d = %d (%d)", i, n, j, ans[j]);
                    first = 0;
                }
                else printf(" * %d (%d)", j, ans[j]);
            }
        printf("\n");
    }
    return 0;
}
