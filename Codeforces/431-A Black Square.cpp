#include <iostream>
using namespace std;
int main() {

    int arr[4];
    for(int i=0;i<4;i++){
        cin >> arr[i];
    }
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        ans+=arr[s[i]-'1'];
    }
    cout << ans << endl;


}
