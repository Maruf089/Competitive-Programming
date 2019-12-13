#include<bits/stdc++.h>

using namespace std;

/// Typedef
typedef long long ll;

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)

#define pf1(a) printf("%lld\n",a)
#define pf2(a,b) printf("%lld %lld\n",a,b)

#define mx 100005
#define mod 10000007


int main()
{
    //freopen ("input.txt", "r", stdin);
    ll tc;

    cin>>tc;
    getchar();
    ll t = 1;
    string arr, brr,crr;

    for(t = 1; t<= tc; t++)
    {
        arr.clear(),brr.clear();
        getline(cin, arr);
        getline(cin, brr);

        ll ln1 = arr.size(), ln2 = brr.size();

        ll ans1 = 0, ans2 = 0;
        for(ll i = 0; arr[i]; i++ )
        {
            arr[i] = tolower(arr[i]);
            if(arr[i]!=' ')
                ans1 += arr[i];
        }

        for(ll i = 0; brr[i]; i++ )
        {
            brr[i] = tolower(brr[i]);
            if(brr[i]!=' ')
                ans2 += brr[i];
        }

        if(ans1 == ans2)
            printf("Case %lld: Yes\n",t);
        else
            printf("Case %lld: No\n",t);

    }

}

