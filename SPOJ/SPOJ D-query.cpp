
#include <bits/stdc++.h>
using namespace std;

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)

#define MOD 1000000007
#define PI acos(-1)
#define ll long long int

ll n,m,a,b,t,i,j,d,cs=0,k,ans=0,l=0,sum1=0,sum=0,Max,Min,num;

int BLK = 555 ;

struct Query
{
    int l,r,idx;
} Q[200009];

int arr[30009], res[200009] ;
int fre[1000009];
int counT = 0 ;

bool comp(Query a,Query b)
{
    if(a.l/BLK != b.l/BLK)
        return a.l/BLK < b.l/BLK ;
    else
        return a.r < b.r;
}

void add(int pos)
{
    fre[arr[pos]]++;
    if(fre[arr[pos]]==1)
        counT++;
}

void remove(int pos)
{
    fre[arr[pos]]--;
    if(fre[arr[pos]]==0)
        counT--;
}

int main()
{
    int n,q;
    cin >> n ;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> q ;
    for(int i=0; i<q; i++)
    {
        cin >> Q[i].l >> Q[i].r ;
        Q[i].idx = i ;
        Q[i].l--, Q[i].r-- ;   /// 0 based
    }

    sort(Q,Q+q,comp);

    int ML = 0, MR = -1 ;

    for(int i=0; i<q; i++)
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

        res[idx] = counT;
    }

    for(int i=0; i<q; i++)
        cout << res[i] << endl;

}

