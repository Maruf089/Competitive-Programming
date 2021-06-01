#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define D(x) cerr<< #x " = "<<x<<endl
#define dbg(x) cerr << #x << " = " << x << endl;
#define D2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;

unordered_set<ll> squares;

bool found = false;
void f(vector<int>& v, int ind, ll sum, int mn) {
    if(found)
        return;
    if(ind == v.size()) {
        if(squares.find(sum) != squares.end()){
            found = true;
            for(auto& i: v)
                cout << i;
            return;
        }
        return;
    }
    for(int i = mn; i <= 9; ++i) {
        int o = v[ind];
        v[ind] = i;
        f(v, ind + 1, sum + i * i - o * o, i);
        v[ind] = o;
    }
}

int main() {

    ll MAX = 81 * 1000000;
    for(ll i = 1; i * i <= MAX; ++i)
        squares.insert(i * i);
    int t;
    cin >> t;
   for(int i=1;i<=100;i++){
        found = false;
        int n = i;
      //  cin >> n;
        vector<int> v(n, 1);
        f(v, 0, n, 1);
        if(found == false)
            cout << "-1";
        cout << "\n";
    }
    return 0;
}
