#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,s1;
ll dp[35][35][65];
ll lcsdp[35][35];
int LCS;
int lcs( int m, int n )
{
    if (m == 0 || n == 0)
        return 0;

    if(lcsdp[m][n]!=-1)
      return lcsdp[m][n];

    if (s[m-1] == s1[n-1])
        return lcsdp[m][n]= 1 + lcs( m-1, n-1);
    else
        return lcsdp[m][n]=max(lcs(m, n-1), lcs(m-1, n));
}
long long func(int i,int j,int num)
{
    if(i>=s.size())
    {
        int l = s1.size()-j;
        if(l+num==LCS)return 1;
        else return 0;
    }
    if(j>=s1.size())
    {
        int l = s.size()-i;
        if(l+num==LCS)return 1;
        else return 0;
    }
    ll &ret=dp[i][j][num];
    if(ret!=-1) return ret;
    if(s[i]==s1[j])
        ret=func(i+1,j+1,num+1);
    else
        ret=func(i+1,j,num+1)+func(i,j+1,num+1);
     return ret;
}
int main()
{
    int n;
    cin >> n ;
    for(int i=0; i<n; i++)
    {
        cin >> s>>s1;
      memset(dp,-1,sizeof(dp));
      memset(lcsdp,-1,sizeof(lcsdp));

        LCS = lcs(s.size(),s1.size());
    //    cout << LCS << endl;
        LCS = LCS+(s.size()-LCS)+(s1.size()-LCS);
        long long ans = func(0,0,0);
        cout<<"Case "<<i+1<<": ";
        cout << LCS << " " << ans << endl;
    }
}
