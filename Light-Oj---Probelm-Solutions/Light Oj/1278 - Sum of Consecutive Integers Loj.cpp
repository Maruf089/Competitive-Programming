#include <bits/stdc++.h>
using namespace std;
#define MAX 10010896
#define LMT 3164
#define ll long long unsigned

int flag[MAX >> 6], primes[800000], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i+=2) if(!ifc(i)) for(j=i*i, k=i<<1; j < MAX; j+=k) isc(j);
    primes[0] = 2, total = 1;
    for(i = 3; i < MAX; i+=2) if(!ifc(i)) primes[total++] = i;
    //for(int i = 0; i <100000; i++) cout<<primes[i]<<" ";
}


ll answer(ll n){
    while(n%2 == 0) n = n/2;
    ll ans = 1;
    for(int i = 0;primes[i]<= sqrt(n) && n!= 1; i++){
        ll c = 0;
        while(n%primes[i] == 0){
            n = n/primes[i];
            c++;
        }
        ans*= (c+1);
    }
    if(n!= 1) ans*=2;
    return ans;
}

int main(){
    int test, cs;
    sieve();
    scanf("%d", &test);
    for(cs = 1; cs <= test; cs++) {
        ll n;
        scanf("%llu", &n);
        printf("Case %d: %llu\n", cs, answer(n)-1);
    }
    return 0;
}
