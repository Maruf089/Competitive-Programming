#include<bits/stdc++.h>
#define mx 100005
#include<bits/stdc++.h>
#define endl '\n'
#define sf scanf
#define pf printf

#define D(x) cout<< #x " = "<<x<<endl
#define cout(case)   cout << "Case " << ++cs << ": " ;
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)

#define PI acos(-1)
#define ll long long int
#define ull unsigned long long


using namespace std;
int arr[mx];
int tree[3*mx];

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

    tree[node] = max( tree[Left],tree[Right] );
 /// D(tree[node]);
}

int Query( int node, int b, int e, int i, int j)
{
    if(i>e||j<b)
        return 0;

    if( b >= i && e <= j)
        return tree[node];

    int Left = node*2;
    int Right = node*2+1;
    int mid  = (b+e)/2;
    int p1 = Query( Left, b, mid, i,j);
    int p2 = Query( Right, mid+1, e,i,j);

    return max(p1,p2);

}

int main()
{
    int i,j,c=0,element,query,start,End,t,s,d,temp=0,a,b;

    scanf("%d",&element);

        for(i=1;i<=element;i++)
            scanf("%d",&arr[i]);

            scanf("%d",&query);

            Init(1,0,element-1);

            while( query-- )
            {
                scanf("%d %d",&start,&End);

                if( start > End )
                    swap(start,End);

                printf("%d\n",Query(1,0,element-1,start-1,End-1));

            }
}

