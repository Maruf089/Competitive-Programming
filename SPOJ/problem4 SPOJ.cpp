#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<x<<endl
#define FOR(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int arr[100],sum;
int dp[100][100];

// if both plays optimals.....
int dpMIN(int i,int j)
{
  if(i>j)
    return 0;
  if(dp[i][j]!=-1)
    return dp[i][j];
  int ans = max( arr[i]+ min( dpMIN(i+2,j) , dpMIN(i+1,j-1) ) , arr[j] + min(dpMIN(i,j-2),dpMIN(i+1,j-1)));
///cout << ans << " ";
  return dp[i][j] = ans;
}
int dpMAX(int i,int j)
{
  if(i>j)
    return 0;
  if(dp[i][j]!=-1)
    return dp[i][j];
  int ans = max(arr[i] + max(dpMAX(i+1,j-1),dpMAX(i+2,j)),arr[j] + max(dpMAX(i+1,j-1),dpMAX(i,j-2)));
  dp[i][j] = ans;
  return ans;
}
int main()
{
  int t,n;
  cin >> t;
  while(t--)
  {
    cin >> n ;
    sum=0;
    memset(dp,-1,sizeof(dp));
    FOR(i,0,n)
    {
      cin >> arr[i];
      sum += arr[i];
    }
    int ans1 = dpMAX(0,n-1);

    FOR(i,0,n){
        FOR(j,0,n){
          cout << dp[i][j] << " ";}
        cout << endl;
  }
    cout << endl;

    memset(dp,-1,sizeof(dp));
    int ans2 = dpMIN(0,n-1);

      FOR(i,0,n){
        FOR(j,0,n){
          cout << dp[i][j] << " ";}
        cout << endl;}

    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
