/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1000005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;


using namespace std;

const int N = 3e5 + 10;
const int tot = 55;
vector<int> pos[N];
int cnt[N];
int a[N];
bool vis[N];

int go(int l, int r, int x)
{
    return upper_bound(pos[x].begin(), pos[x].end(), r) -
           lower_bound(pos[x].begin(), pos[x].end(), l);
}

int main()
{
    FASTIO

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
        cnt[a[i]]++;
    }

    mt19937_64 rng = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int target = (r - l + 1) / k;
        int ans = N;
        vector<int> done;
        done.reserve(tot);

        for (int i = 0; i < 100; i++)
        {
            int idx = uniform_int_distribution<int>(l, r)(rng);

            if (vis[idx])
                continue;
            if (a[idx] >= ans)
                continue;
            if (cnt[a[idx]] <= target)
                continue;
            if (go(l, r, a[idx]) > target)
                ans = min(ans, a[idx]);
            done.push_back(idx);
            vis[idx] = 1;
            if ((int)done.size() == tot)
                break;
        }
        for (auto x : done)
            vis[x] = 0;
        if (ans == N)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}
