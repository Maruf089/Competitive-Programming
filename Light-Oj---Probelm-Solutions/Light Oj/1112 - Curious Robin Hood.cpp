#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int arr[100005];
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

    tree[node] = tree[Left] + tree[Right];
}

int Query( int node, int b, int e, int i, int j)
{
    if( b >= i && e <= j)
        return tree[node];
        if( i>e || j<b)
            return 0;

    int Left = node*2;
    int Right = node*2+1;
    int mid  = (b+e)/2;
    int p1 = Query( Left, b, mid, i,j);
    int p2 = Query( Right, mid+1, e,i,j);

    return (p1+p2);
}

void Update ( int node, int b, int e, int i, int newvalue)
{
    if( b>=i && e<=i )
    {
        arr[i] = newvalue;
        tree[node] = arr[i];
        return ;
    }
     if( i>e || b>i )
        return ;

    int Left = node*2;
    int Right = node*2+1;
    int mid  = (b+e)/2;

    Update( Left, b, mid, i, newvalue );
    Update( Right, mid+1, e, i, newvalue );

 tree[node] = tree[Left] + tree[Right];
}

int main()
{
    int t,com,element,query,i,j,value,index_i,index_j,node,c=0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++c);

        scanf("%d %d",&element,&query);

        for(int i=0;i<element;i++)
            scanf("%d",&arr[i]);

        Init(1,0,element-1);

        while(query--)
        {
            scanf("%d",&com);

            if(com==1)
            {
                scanf("%d",&index_i);
                printf("%d\n",arr[index_i]);
                arr[index_i] = 0;
                Update(1,0,element-1,index_i,0);
            }
            else if(com==2)
            {
                scanf("%d %d",&index_i,&value);
                arr[index_i] += value;
                Update(1,0,element-1,index_i,arr[index_i]);
            }
            else if( com==3 )
            {
                scanf("%d %d",&index_i,&index_j);
                printf("%d\n",Query(1,0,element-1,index_i,index_j));
            }
        }
    }

}
