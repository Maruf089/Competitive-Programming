#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll int number_of_trailing_zeros(ll int n)
{
    ll int cnt=0;
    while(n)
    {
        n/=5;
        cnt+=n;
    }
    return cnt;
}

// driver code
int main()
{
	long long n,t;

	cin >> t ;
	while(t--){
    cin >> n ;
	cout << number_of_trailing_zeros(n) << endl;
	}
}


