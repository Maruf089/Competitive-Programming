#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef pair< int , int >PII;
typedef tree<PII,null_type,less<PII>,rb_tree_tag,tree_order_statistics_node_update>
ordered_set;

const int MAXN = 2e5+7;
int a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    long long ans = 0;
    ordered_set ost;
    for (int i = 1; i <= n; i++) {
        ans += ost.order_of_key(PII(a[i]-b[i], 0));
        ost.insert(PII(b[i]-a[i], i));
    }

    cout << ans << "\n";

    return 0;
}
