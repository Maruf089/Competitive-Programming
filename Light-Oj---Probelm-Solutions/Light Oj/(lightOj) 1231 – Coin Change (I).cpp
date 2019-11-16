#include<iostream>
#include<cstring>
#include<cstdio>
#define MOD 100000007
#define get(n) scanf("%d", &n)
#define loop(n) for(int i=0; i<n; i++)
#define MAXX 1001
#define mem(x, y) memset(x, y, sizeof(x))
#define loopi(i,n) for(int i=0; i<n; i++)
#define lld long long int
using namespace std;

lld dp[MAXX][51];
int coin[51];
int countCoin[51];
int target, n;

lld rec(int amount, int index)
{

   if(index==n)
   {
       if(amount==0) return 1;
       return 0;
   }


   if(amount==0)
   {
       return 1;
   }


   if(amount<0)
   {
       return 0;
   }

   if(dp[amount][index] != -1)
   {
       return dp[amount][index];
   }

   lld result = 0;
   for(int i=0; i<=countCoin[index]; i++)
   {
       result = (result + rec(amount - coin[index]*i, index+1)) % MOD;
   }

   dp[amount][index] = result;
   return result;

}



int main()
{
    int cases, caseno = 0;

    get(cases);
    while(cases--)
    {
        loopi(i, MAXX)
        {
            loopi(j, 51)
            {
                dp[i][j] = -1;
            }
        }


        get(n);
        get(target);


        loopi(i,n)     get(coin[i]);
        loopi(i,n)     get(countCoin[i]);


        printf("Case %d: %lld\n", ++caseno, rec(target, 0));

    }
    return 0;

}

/// another

/*
/// call change(0,0)
int change (int i , int ase) {
 if (i >= n) {
  if (ase == K) return 1;
  else return 0;
 }
 if (ase > K) return 0;
 //if (ase == K) return 1;
 if (dp[i][ase] != -1) return dp[i][ase];
 int tt = 0;
 for (int ii = 1; ii <= mtake[i]; ii++) {
  if (ase + coin[i] * ii <= K)
  tt += change (i + 1 , ase + coin[i] * ii) % mod;
  else break;
 }
 tt += change (i + 1 , ase) % mod;
 dp[i][ase] = tt % mod;
 return dp[i][ase];
}

*/
