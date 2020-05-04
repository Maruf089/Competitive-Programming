#include <bits/stdc++.h>
using namespace std;
#define MAXN 200009
#define D(x) cout<< #x " = "<<x<<endl
int N, K, arr[MAXN], sum[MAXN];
int dp[MAXN][2];

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		sum[i] = arr[i] + (i > 0 ? sum[i-1] : 0);
   // D(sum[i]);
	}
	for(int i=0; i<N; i++) {
		dp[i][0] = max(dp[i-1][0], sum[i] - (i >= K ? sum[i-K] : 0));
   // D(dp[i][0]);
		dp[i][1] = max(dp[i-1][1], sum[i] - (i >= K ? sum[i-K] : 0) + (i >= K ? dp[i-K][0] : 0));
  //  D(dp[i][1]);

	}
	printf("%d\n", dp[N-1][1]);
	return 0;
}
