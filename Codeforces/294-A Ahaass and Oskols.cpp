#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin >> n;
    int arr[n+2];
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int m;
    int x,y;
    cin >> m;
    while(m--){
        cin >> x >> y;
        arr[x-1]+=y-1;
        arr[x+1]+=(arr[x]-y);
        arr[x]=0;
    }
    for(int i=1;i<=n;i++){
        cout << arr[i] << endl;
    }

}
