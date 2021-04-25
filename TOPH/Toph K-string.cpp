#include<bits/stdc++.h>
using namespace std;

int n, m, x, y, z, k;
vector < int > vec;
int cnt[40];
string str;

int main()
{
    cin >> n >> k >> str;
    for(char ch : str){
        cnt[ch - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(cnt[i] == 0) continue;
        vec.push_back(cnt[i]);
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    if(vec.size() <= k){
        cout << k - vec.size() << endl;
        return 0;
    }
    int ans = 0;
    for(int i = k; i < vec.size(); i++) ans += vec[i];

    cout << ans << endl;



    return 0;
}
