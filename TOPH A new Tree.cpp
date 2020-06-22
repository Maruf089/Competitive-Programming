#include <bits/stdc++.h>
using namespace std;
#define ln '\n'

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define MOD 1000000007
#define PI acos(-1)
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define F first
#define S second
#define sz size()
#define LCM(a,b) (a*(b/__gcd(a,b)))
//#define harmonic(n) 0.57721566490153286060651209+log(n)+1.0/(2*n)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))

#define fastio ios_base::sync_with_stdio(false)



/// ************************************** Code starts here ****************************************** */


const int mx = (int)1e5+9;
vector<pair<int,int>>PAIR;
int BLOCK,counT=0;
int cnt[mx];

void add(int x)
{
    if(cnt[PAIR[x].F]==1)counT++;
    if(cnt[PAIR[x].S]==1)counT++;
    cnt[PAIR[x].F]++;
    cnt[PAIR[x].S]++;
}
void remove(int x)
{
    if(cnt[PAIR[x].F]==2)counT--;
    if(cnt[PAIR[x].S]==2)counT--;
    cnt[PAIR[x].F]--;
    cnt[PAIR[x].S]--;

}
struct node
{
    int l,r,idx;
};

bool cmp(node a,node b){
    if(a.l / BLOCK != b.l / BLOCK)return a.l / BLOCK < b.l / BLOCK;
    return ((a.l / BLOCK) & 1) ? a.r < b.r : a.r > b.r ;
}

int main()
{
    int n,a,b,i,m,j;
    scanf("%d",&n);
    BLOCK = sqrt(n);

    PAIR.resize(n+3);

    f0(i,n-1)
    {
        scanf("%d %d",&PAIR[i].F,&PAIR[i].S);
    }

    scanf("%d",&m);
    node Q[m+2];
    int res[m+2];

    f0(i,m)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        l--,r--;
        Q[i].l = l ;
        Q[i].r = r ;
        Q[i].idx = i;
    }
    sort(Q,Q+m,cmp);

    int ML = 0,MR = -1;
    for(int i=0; i<m; i++)
    {
        int L =Q[i].l;
        int R = Q[i].r;
        int idx = Q[i].idx;

        /// extend range
        while(MR<R)
            MR++,add(MR);
        while(ML>L)
            ML--,add(ML);

        /// reduce range
        while(MR>R)
            remove(MR),MR--;
        while(ML<L)
            remove(ML),ML++;

        res[idx] = counT+1;
    }

    f0(i,m)
    printf("%d\n",res[i]);

}
