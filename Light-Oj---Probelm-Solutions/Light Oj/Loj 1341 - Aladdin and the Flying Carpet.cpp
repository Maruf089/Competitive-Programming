#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6+5;
bool prime[MAXN];
LL p[MAXN],k;
void isprime()
{
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    k = 0;
    for(LL i=2; i<MAXN; i++)
    {
        if(prime[i])
        {
            p[k++] = i;
            for(LL j=i*i; j<MAXN; j+=i)
                prime[j] = false;
        }
    }
}

LL Solve(LL m)
{
    LL ret = 1;
    for(LL i=0; p[i]*p[i]<=m&&i<k; i++)
    {
        LL cnt = 0;
        if(m%p[i] == 0)
        {
            while(m%p[i] == 0)
            {
                cnt++;
                m /= p[i];
            }
            ret *= (cnt+1);
        }
    }
    if(m > 1)
        ret *= 2;
    return ret;
}
int main()
{
    isprime();
    int T;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        LL s,a;
        cin>>s>>a;
        if(a*a >= s)
            printf("Case %d: 0\n",cas);
        else
        {
            LL ret = Solve(s);
            ret /= 2;
            for(LL i=1; i<a; i++)
                if(s % i == 0)
                    ret--;
            printf("Case %d: %lld\n",cas,ret);
        }
    }
    return 0;
}
