#include<bits/stdc++.h>
using namespace std;
#define ll long long


#define mxx 100000100
bitset <mxx> mark;
vector <int> primes;


void sieve()
{
    mark[0] = mark[1] = 1;
    primes.push_back(2);
    int lim = sqrt(mxx * 1.0) + 2;
    for (int i = 4; i < mxx; i += 2)
        mark[i] = 1;
    for (int i = 3; i < mxx; i += 2)
    {
        if (!mark[i])
        {
            primes.push_back(i);
            if (i <= lim)
                for (int j = i * i; j < mxx; j += i)
                    mark[j] = 1;
        }
    }
}
int find_fre(int n,int p)
{
    int cnt=0;
    while(n)
    {
        cnt+=n/p;
        n/=p;
    }
    return cnt;
}
long long big_mod(ll num,int p,ll mod)
{
    ll sum=1,temp=num;
    while(p)
    {
        if(p&1)
            sum=(sum*temp)%mod;
        temp=(temp*temp)%mod;
        p=p>>1;
    }
    return sum;
}

int main()
{
    sieve();
    int t,n,low,high,mid,temp;
    scanf("%d",&t);
    ll m,x,y,res;
    while(t--)
    {
        scanf("%d%lld",&n,&m);
        res=1;
        if(n<=2)
        {
            printf("%lld\n",0LL);
            continue;
        }
        int pos=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
        for(int i=1; primes[i]<=n; i++)
        {
            x=find_fre(n,primes[i]);
            y=find_fre(n,primes[i+1]);
            if(x==y)
            {
                low=i,high=pos+2;
                while(low<=high)
                {
                    mid=(low+high)>>1;
                    if(find_fre(n,primes[mid])==x)
                    {
                        temp=mid;
                        low=mid+1;
                    }
                    else
                        high=mid-1;
                }
                res=res*big_mod(x+1,(temp-i)+1,m);
                if(res>=m) res=res%m;
                i=temp;
            }
            else
            {
                res = res*(x+1);
                if(res>=m)
                    res=res%m;
            }

        }
        res--;
        if(res<0) res=res+m;
        printf("%lld\n",res);

    }
}
