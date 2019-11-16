using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 50005

void solve()
{
    long long p,l;
    cin>>p>>l;
    if ( p - l <= l)
    {
        cout<<" impossible";
        return;
    }
    long long n = p-l;
    long long sn = sqrt(n);
    set<long long> ans;
    for(int i = 1; i <= sn; ++i)
        if(n%i == 0)
        {
            ans.insert(i);
            ans.insert(n/i);
        }
    for(auto i : ans)
        if(i>l)
            cout<<" "<<i;
}

int main()
{
    int tc;
    cin>>tc;
    for(int i = 0; i< tc; ++i)
    {
        cout<<"Case "<<(i+1)<<":";
        solve();
        cout<<endl;
    }

    return 0;
}
