/// 2 st nd -- return the sum of the squares of the numbers with indices in [st, nd]
/// 1 st nd x -- add "x" to all numbers with indices in [st, nd]
/// 0 st nd x -- set all numbers with indices in [st, nd] to "x"

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
#define segment_tree int l=n*2,r=l+1,mid=(b+e)/2
struct data
{
    ll sum,sqrsum,lazy,upd;
};
data tree[3*mx];
ll x ;
ll ara[mx];

void init(int n, int b, int e)
{
    if(b==e)
    {
        tree[n].sum=ara[b];
        tree[n].sqrsum=sqr(ara[b]);
        tree[n].lazy=0;
        tree[n].upd=0;
        return;
    }
    segment_tree;
    init(l,b,mid);
    init(r,mid+1,e);
    tree[n].sum=tree[l].sum+tree[r].sum;
    tree[n].sqrsum=tree[l].sqrsum+tree[r].sqrsum;
    tree[n].lazy=0;
    tree[n].upd=0;
}

void update()



int main()
{

    int kase = 1;
    scanf("%d", &t);
    while(t-- != 0)
    {
        printf("Case %d:\n", kase++);
        scanf("%d %d", &n, &q);

        for(int i = 1; i <= n; ++i)
            scanf("%d", a + i);

        init(1, 1, n);

        while(q-- != 0)
        {
            int type,s,e;
            scanf("%d %d %d", &type, &s, &e);

            if(type == 2)
            {
                ll ans = query(1,1,n,s,e);
                printf("%lld\n",ans);
            }
            else
            {
                scanf("%d",&x);
                if(type==1)
                    update(1,1,n,b,c,d,1);
                else
                    update(1,1,n,b,c,d,0);

            }
        }
    }

    return 0;
}
