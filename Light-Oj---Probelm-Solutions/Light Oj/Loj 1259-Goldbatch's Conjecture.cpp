#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define LL long long int
#define ULL unsigned LL

const int inf=1<<30;
const LL INF=1e18;
const int MOD=1e9+7;

vector<int> primes;
char chk[10000007];
int mx = 10000000;
void PG()
{
    for(int i=3; i<=mx; i+=2)
    {
        if(chk[i]==0)
        {
            primes.push_back(i);
            for(int j=2*i; j<=mx; j+=i)
                chk[j]=1;
        }
    }
}

int main()
{
    int tn;
    scanf("%d", &tn);

    PG();

    for(int cs=1; cs<=tn; cs++)
    {
        int n;
        scanf("%d", &n);
        int cnt=0;
        if(n==4)cnt=1;

        for(int i=0; i<primes.size(); i++)
        {
            int x = primes[i];
            int y = n - x;

            if(y<x) break;

            if(chk[y]==0)
                cnt++;
        }
        printf("Case %d: %d\n", cs, cnt);

    }
    return 0;
}
