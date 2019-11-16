#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
typedef long long ll;
long long arr[100001];
long long tree[3*100001];

void Init( ll node, ll b, ll e)
{
    if(b>e)
        return;
    if( b == e)
    {
        tree[node] = arr[b];
        return ;
    }
    ll Left = node*2;
    ll Right = node*2+1;
    ll mid  = (b+e)/2;
    Init( Left, b, mid);
    Init( Right, mid+1, e);

    tree[node] = min(tree[Left] , tree[Right]);
}

long long Query( ll node, ll b, ll e, ll i, ll j)
{
    if( b >= i && e <= j)
        return tree[node];

    if( j<b || i>e )
        return INF;

    ll Left = node*2;
    ll Right = node*2+1;
    ll mid  = (b+e)/2;
    long p1 = Query( Left, b, mid, i,j);
    long p2 = Query( Right, mid+1, e, i,j);

    return min(p1,p2);
}

/*
void Update( ll node, ll b, ll e, ll i, ll j, ll newvalue)
{
    if( b >= i && e <= j)
    {
        tree[node] = newvalue;
        return ;
    }
    if( j<b || i>e )
        return ;

    ll Left = node*2;
    ll Right = node*2+1;
    ll mid  = (b+e)/2;
    Update( Left, b, mid, i,j,newvalue);
    Update( Right, mid+1, e, i,j,newvalue);
 tree[node] = tree[Left] + tree[Right];
}

*/
int main()
{
    ll t,i,j,c=0,element,query,start,End;
    scanf("%lld",&t);

    while(t--)
    {
       //printf("\n");
       printf("Scenario #%lld:\n",++c);

        scanf("%lld %lld",&element,&query);

        for(i=0;i<element;i++)
            scanf("%lld",&arr[i]);

            Init(1,0,element-1);

            while( query-- )
            {
                scanf("%lld %lld",&start,&End);
                printf("%lld\n",Query(1,0,element-1,start-1,End-1));

            }

 }
}
