#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int tree[3*100005];

void Init( int node, int b, int e)
{
    if( b == e)
    {
        tree[node] = arr[b];
        return ;
    }
    int Left = node*2;
    int Right = node*2+1;
    int mid  = (b+e)/2;
    Init( Left, b, mid);
    Init( Right, mid+1, e);

    tree[node] = min( tree[Left],tree[Right] );
}

int Query( int node, int b, int e, int i, int j)
{
    if( b >= i && e <= j)
        return tree[node];

    int Left = node*2;
    int Right = node*2+1;
    int mid  = (b+e)/2;

    if( j<=mid )
        return Query( Left, b, mid, i,j);

    else if( i > mid )
    return Query( Right, mid+1, e,i,j);

    else
    {
        int p1 = Query( Left, b, mid, i,j);
        int p2 = Query( Right, mid+1, e,i,j);

        return min(p1,p2);
    }

}

int main()
{
    int t,i,j,c=0,element,query,start,End;
    scanf("%d",&t);

    while(t--)
    {
       /// printf("\n");
        printf("Case %d:\n",++c);

        scanf("%d %d",&element,&query);

        for(i=0;i<element;i++)
            scanf("%d",&arr[i]);

            Init(1,0,element-1);

            while( query-- )
            {
                scanf("%d %d",&start,&End);
                printf("%d\n",Query(1,0,element-1,start-1,End-1));

            }

    }
}

