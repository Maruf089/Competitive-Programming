///*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*///

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const int MAX = (int)3000009;

int phi[MAX+9];
ull res[MAX+9];
ull DP[MAX+9];

void generatePhi()
{
    phi[1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        if(phi[i] == 0)
        {
            phi[i] = i - 1;
            for(int j = i*2; j < MAX; j += i)
            {
                if(phi[j] == 0)
                    phi[j] = j;
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}

void preCal()
{
    DP[0] = DP[1] = 0 ;
    for (ull i = 2; i <= MAX; ++i)
    {
        for (ull j = i; j <= MAX; j += i)
        {
            res[j] += (j*phi[i]/2)*i;
        }
        DP[i] = DP[i-1] + res[i];
    }
}


int main()
{
    generatePhi();
    preCal();

    int t , cs = 0;
    scanf("%d", &t);
    while(t--)
    {
        ull n;
        scanf("%llu", &n);
        printf("Case %d: %llu\n", ++cs, DP[n]);
    }

}



