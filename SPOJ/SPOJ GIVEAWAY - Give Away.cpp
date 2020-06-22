#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln endl
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 5e5+9;
int a[MAXN];
vector<int>blk[710];

int main()
{
    io;
    int n,q;
    cin >> n  ;
    int sqrtn = sqrt(n);

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        blk[i/sqrtn].push_back(a[i]);
    }
    cin >> q ;

    int block_num = ceil( (n*1.00)/sqrtn*1.00);
    for(int i=0; i<block_num; i++)
        sort(blk[i].begin(),blk[i].end());

    while(q--)
    {
        int c ;
        cin >> c ;
        if(c==1)
        {

            int idx,newVal;
            cin >> idx >> newVal;
            idx--;

            int block = idx/sqrtn;
            int initVal = a[idx];

            int k = upper_bound(blk[block].begin(),blk[block].end(),initVal)-blk[block].begin();
            k--;
            if(k<0)
                k = 0;

            blk[block][k] = newVal;
            a[idx] = newVal;
            sort(blk[block].begin(),blk[block].end());
        }
        else
        {
             int l, r, x;
            cin >> l >> r >> x;
            --l;
            --r;
            int leftBlock = l/sqrtn;
            int rightBlock = r/sqrtn;
            int ans = 0;
            if(leftBlock == rightBlock)
            {
                for(int i = l; i <= r; i++)
                {
                    if(a[i] >= x)
                        ans++;
                }
                cout << ans << endl;
            }
            else
            {
                if(l%sqrtn != 0)
                    leftBlock++;
                int i;
                for(i = l; i < leftBlock*sqrtn; i++)
                    if(a[i] >= x)
                        ans++;
                while(i+sqrtn-1 <= r)
                {
                    int bb = i/sqrtn;
                    ans += blk[bb].end() - lower_bound(blk[bb].begin(), blk[bb].end(), x);
                    i += sqrtn;
                }
                while(i <= r)
                {
                    if(a[i] >= x)
                        ans++;
                    i++;
                }
                cout << ans << endl;
            }
        }

    }
}





/*


    it has to be Accepted
    https://www.codechef.com/problems/GIVEAWAY
    same problem and there got AC



    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define ll long long
    using namespace std;
    using namespace __gnu_pbds;

    typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
    using namespace std;
    int a[500005];
    vector< pbds > trees(2000006);
    void build(int node,int s,int e)
    {
        if(s==e)
        {
            trees[node].insert(a[s]);
            return;
        }
        int m=(s+e)/2;
        build(2*node,s,m);
        build(2*node+1,m+1,e);
        for(auto it= trees[2*node].begin(); it!= trees[2*node].end(); it++)
            trees[node].insert(*it);
        for(auto it= trees[2*node+1].begin(); it!= trees[2*node+1].end(); it++)
            trees[node].insert(*it);
        //merge(trees[2*node].begin(),trees[2*node].end(),trees[2*node+1].begin(),trees[2*node+1].end(),back_inserter(trees[node]));
    }
    int query(int node,int s,int e,int l,int r,int c)
    {
        if(r<s || l>e)
            return 0;
        if(s>=l && e<=r)
        {
            return (int)trees[node].size()-(int)trees[node].order_of_key(c);
        }
        int m = (s+e)/2;
        int la = query(2*node,s,m,l,r,c);
        int ra = query(2*node+1,m+1,e,l,r,c);
        return la+ra;
    }
    void update(int node,int s,int e,int idx,int val)
    {
        trees[node].erase(trees[node].find(a[idx]));
        trees[node].insert(val);
        if(s==e)
        {
            a[idx]=val;
            return;
        }
        int m = (s+e)/2;
        if(idx>=s && idx<=m)
            update(2*node,s,m,idx,val);
        else
            update(2*node+1,m+1,e,idx,val);
    }
    int main()
    {
        int n,q;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        build(1,0,n-1);
        scanf("%d", &q);
        while(q--)
        {
            int d;
            scanf("%d",&d);
            if(d==0)
            {
                int l,r,c;
                scanf("%d%d%d",&l,&r,&c);
                 printf("%d\n"query(1,0,n-1,l-1,r-1,c));
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                update(1,0,n-1,l-1,r);
            }
        }
        return 0;
    }


*/
