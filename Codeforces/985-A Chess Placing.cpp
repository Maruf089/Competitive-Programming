#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x, y[105];
int main(){
	cin >> x;

	for (int i = 0; i < x / 2; i++)
		cin >> y[i];
	ll sum = 0;
	sort(y, y + x / 2);
	ll c = 2;
	for (int i = 0; i < x / 2; i++){
		sum += abs(y[i] - c);
		c += 2;
	}
	ll ans = 0;
	c = 1;
	for (int i = 0; i < x / 2; i++){
		ans += abs(y[i] - c);
		c += 2;
	}

	cout << min(sum, ans) << endl;
	return 0;
}
