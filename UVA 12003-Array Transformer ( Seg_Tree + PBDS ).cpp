#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll                       long long
#define pli                      pair <ll, int>
#define MK                       make_pair
#define ff                       first
#define ss                       second

template <typename T> using orderedSet = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int maxn = 300000 + 5;

int ptr;

struct segmentTree
{
    orderedSet <pli> oms;

    void assignLeaf(ll val, int ptr)
    {
        oms.insert({val, ptr});
    }
    void marge(segmentTree &L, segmentTree &R)
    {
        orderedSet <pli>::iterator it;
        for (it = L.oms.begin(); it != L.oms.end(); it++)
            oms.insert({it->ff, it->ss});
        for (it = R.oms.begin(); it != R.oms.end(); it++)
            oms.insert({it->ff, it->ss});
    }
    int lessNum(ll v)
    {
        int cnt = oms.order_of_key({v, -1});
        return cnt;
    }
    void eraseOld(ll v)
    {
        orderedSet <pli>::iterator it;
        it = oms.lower_bound({v, -1});
        oms.erase(it);
    }
    void insertNew(ll v, int ptr)
    {
        oms.insert({v, ptr});
    }
} Tree[maxn << 2];

ll arr[maxn];

void build(int node, int a, int b)
{
    if (a == b)
    {
        Tree[node].assignLeaf(arr[a], ++ptr);
        return;
    }
    int lft = node << 1;
    int rgt = lft|1;
    int mid = (a+b) >> 1;
    build(lft, a, mid);
    build(rgt, mid+1, b);
    Tree[node].marge(Tree[lft], Tree[rgt]);
}

int query(int node, int a, int b, int i, int j, ll v)
{
    if (a > b || a > j || b < i)
        return 0;
    if (a >= i && b <= j)
        return Tree[node].lessNum(v);
    int lft = node << 1;
    int rgt = lft | 1;
    int mid = (a+b) >> 1;
    int p1, p2;
    p1 = query(lft, a, mid, i, j, v);
    p2 = query(rgt, mid+1, b, i, j, v);
    return p1 + p2;
}

void update(int node, int a, int b, int pos, ll old, ll newNum, int ptr)
{
    if (a > b || a > pos || b < pos)
        return;
    if (a >= pos && b <= pos)
    {
        arr[pos] = newNum;
        Tree[node].eraseOld(old);
        Tree[node].insertNew(newNum, ptr);
        return;
    }
    int lft = node << 1;
    int rgt = lft | 1;
    int mid = (a+b) >> 1;
    update(lft, a, mid, pos, old, newNum, ptr);
    update(rgt, mid+1, b, pos, old, newNum, ptr);
    Tree[node].eraseOld(old);
    Tree[node].insertNew(newNum, ptr);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m; // m : query
    ll u;
    scanf("%d %d %lld", &n, &m, &u);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
    build(1, 1, n);
    while (m--)
    {
        int L, R, p;
        ll v;
        scanf("%d %d %lld %d", &L, &R, &v, &p);
        int k = query(1, 1, n, L, R, v);
        ll newNum = (u*k)/(R-L+1);
        update(1, 1, n, p, arr[p], newNum, ++ptr);
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", arr[i]);
}
