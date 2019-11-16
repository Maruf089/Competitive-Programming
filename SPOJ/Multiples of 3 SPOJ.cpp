#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define D(x) cerr << #x << ": " << x << endl;
#define mx 100005
#define ll long long
using namespace std;


int arr[mx];
int lazy[4*mx];
struct segment
{
    ll counT0,counT1,counT2;
    void add()
    {
        int temp ;
        temp = counT0;
        counT0 = counT2;
        counT2 = counT1 ;
        counT1 = temp ;
    }

    void mergee(segment left, segment right )
    {
        counT0 = left.counT0 + right.counT0;
        counT1 = left.counT1 + right.counT1;
        counT2 = left.counT2 + right.counT2;
    }
} tree[mx * 4];

void build(int node, int b, int e)
{

    if (b == e)
    {
        tree[node].counT0 = 1;
        tree[node].counT1 = 0 ;
        tree[node].counT2 = 0 ;

         cout << " b == e " <<endl;
        cout<<" tree [ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    tree[node].mergee( tree[Left],tree[Right] );

    cout<<" tree[ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);
}

void update(int node, int b, int e, int i, int j)
{
 D(lazy[node]);

    if(lazy[node]%3==1)
    {
        tree[node].add();

    cout << "If 1 " << endl;
          cout<<" tree [ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);

        if(b!=e)
        {
            lazy[2*node+1] += lazy[node]%3;
            lazy[2*node+2] += lazy[node]%3;
        }

    }
    else if(lazy[node]%3==2)
    {
        tree[node].add();
        tree[node].add();

     cout << "If 2 " << endl;
          cout<<" tree [ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);


        if(b!=e)
        {
            lazy[2*node+1] += lazy[node]%3;
            lazy[2*node+2] += lazy[node]%3;
        }
    }
    else if(lazy[node] && lazy[node]%3 == 0)
    {

         cout << "If 2 " << endl;
          cout<<" tree [ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);


        if(b!=e)
        {
            lazy[2*node+1] += lazy[node]%3;
            lazy[2*node+2] += lazy[node]%3;
        }
    }
    lazy[node] = 0 ;

D(lazy[2*node+1]);
D(lazy[2*node+2]);

    if (i > e || j < b)
        return;
    if (b >= i and e <= j)
    {
        tree[node].add();
    D(b);D(e);
    D(i);D(j);
        if(b!=e)
        {
            lazy[2*node+1] += 1;
            lazy[2*node+2] += 1;
        }
    D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);
        return;
    }
    int Left = node * 2 ;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j);
    update(Right, mid + 1, e, i, j);
    tree[node].mergee( tree[Left],tree[Right] );


        cout<<" tree [ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);
}

segment query(int node, int b, int e, int i, int j, ll carry = 0)
{
    segment ans ;
    ans.counT0 = ans.counT1 = ans.counT2 = 0 ;

D(lazy[node]);

    if(lazy[node]%3==1)
    {

        tree[node].add();

          cout << "If 1 in Query \n" << endl;
          cout<<" tree [ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);

        if(b!=e)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
    }
    else if(lazy[node]%3==2)
    {
        tree[node].add();
        tree[node].add();

          cout << "If 2 in Query \n" << endl;
          cout<<" tree [ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);


        if(b!=e)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
    }
     else if(lazy[node] && lazy[node]%3 == 0)
    {

          cout << "If 3 in Query \n" << endl;
          cout<<" tree [ "<<node<<" ] ";
        D(tree[node].counT0);D(tree[node].counT1);D(tree[node].counT2);

        if(b!=e)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
    }

    lazy[node] = 0 ;

D(lazy[2*node+1]);
D(lazy[2*node+2]);

    if (i > e || j < b)
        return ans;

    if (b >= i and e <= j)
        {
        cout << " Return tree node \n";
            return tree[node];
        }

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    segment p1 = query(Left, b, mid, i, j);
    segment p2 = query(Right, mid + 1, e, i, j);

    ans.mergee(p1, p2);

     cout<<" tree [ "<<node<<" ] \n";
        D(ans.counT0);D(ans.counT1);D(ans.counT2);

    return ans ;
}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    int type,a,b;
    build(1,0,n-1);
    while(q--)
    {
        scanf("%d %d %d",&type,&a,&b);
        if(type)
        {
            printf("%lld\n",query(1,0,n-1,a,b).counT0);
        }
        else
        {
            update(1,0,n-1,a,b);
        }
    }

}

/*


#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y, z;
};

struct segment_tree {
    vector<point> st;
    vector<int> lazy;
    size_t n;

    inline int left(int p) {
        return p << 1;
    }

    inline int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if (L == R)
            st[p].x = 1;
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            st[p].x = st[left(p)].x + st[right(p)].x;
        }
    }

    void propagate(int p, int L, int R) {
        if (lazy[p]) {
            lazy[p] %= 3;
            if (L != R) {
                lazy[left(p)] += lazy[p];
                lazy[right(p)] += lazy[p];
            }

            if (lazy[p] == 1) {
                int temp = st[p].z;
                st[p].z = st[p].y;
                st[p].y = st[p].x;
                st[p].x = temp;
            }
            else if (lazy[p] == 2) {
                int temp = st[p].z;
                st[p].z = st[p].x;
                st[p].x = st[p].y;
                st[p].y = temp;
            }
            lazy[p] = 0;
        }
    }

    point update(int p, int L, int R, int i, int j) {
        propagate(p, L, R);

        if (L > j || R < i)
            return st[p];

        if (L >= i && R <= j) {
            lazy[p] = 1;
            propagate(p, L, R);
            return st[p];
        }


        point p1 = update(left(p), L, (L + R) / 2, i, j);
        point p2 = update(right(p), (L + R) / 2 + 1, R, i, j);
        st[p].x = p1.x + p2.x;
        st[p].y = p1.y + p2.y;
        st[p].z = p1.z + p2.z;
        return st[p];
    }

    int query(int p, int L, int R, int i, int j) {
        propagate(p, L, R);

        if (L > j || R < i)
            return 0;

        if (L >= i && R <= j)
            return st[p].x;

        return query(left(p), L, (L + R) / 2, i, j) +
               query(right(p), (L + R) / 2 + 1, R, i, j);
    }

    segment_tree(int N): n(N) {
        st.assign(4 * n, point());
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int update(int i, int j) {
        update(1, 0, n - 1, i, j);
    }

    int query(int i, int j) {
        return query(1, 0, n - 1, i, j);
    }
};


int main() {
    int N, Q , t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
    printf("Case %d:\n",i);
    scanf("%d %d", &N, &Q);
    segment_tree st(N);
    while (Q--) {
        int op, A, B;
        scanf("%d %d %d", &op, &A, &B);
        if (op == 0)
            st.update(A, B);
        else
            printf("%d\n", st.query(A, B));
    }
    }
}
*/
