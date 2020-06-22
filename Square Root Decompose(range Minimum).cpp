///*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*///

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define sf scanf
#define pf printf

int arr[100009];
int block[10000];
int BLK,i,n,j,q;

/// Time Complexity : O(1)
void update(int idx,int val) /// this update is for sum operation
{
   int blocknumber = idx/BLK;
   block[blocknumber] += val-arr[idx];
   arr[idx] = val;
}

/// Time Complexity : O(sqrt(n))
int get_Min_Query(int l,int r)
{
    int LB = l/BLK;
    int RB = r/BLK;
    int mn = INT_MAX;

    if(LB==RB)
    {
        for(int i=l; i<=r; i++)
            mn = min(mn,arr[i]);
    }
    else
    {
        /// traversing first block in range
        for(int i=l; i<BLK*(LB+1); i++)
            mn = min(mn,arr[i]);

        /// traversing completely overlapped blocks in range
        for(int i=LB+1; i<RB; i++)
            mn = min(mn,block[i]);

        /// traversing last block in range
        for(int i=BLK*RB; i<=r; i++)
            mn = min(mn,arr[i]);

    }
    return mn;
}

void preprocess(int input[],int n)
{
    for(int i=0;i<=sqrt(1000000);i++)
        block[i] = INT_MAX;
    /// initiating block pointer
    int blk_idx = -1;
    if(sqrt(n)*sqrt(n)==n)
        BLK = sqrt(n);
    else
        BLK  = sqrt(n)+1;

    /// building the decomposed array
    for(i=0;i<n;i++)
    {
        arr[i] = input[i];
        if(i%BLK==0)
            blk_idx++;
        block[blk_idx] = min(input[i],block[blk_idx]);
    }
}
int main()
{
    cin >> n ;
    int input[n+9];
    for(int i=0;i<n;i++)
        cin >> input[i];

    preprocess(input,n);

    cin >> q ;
    while(q--)
    {
        int l , r ;
        cin >> l >> r ;

        cout << get_Min_Query(l,r) << endl;
    }
}
