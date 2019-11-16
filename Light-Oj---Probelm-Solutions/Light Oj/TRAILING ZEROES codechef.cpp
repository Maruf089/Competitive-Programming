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

long long findNum(long long n)
{
	if (n==1)
		return 5;
	long long low = 0;
	long long high = 5*n+100;

	ll ans  = 0 ;
	while (low <high)
	{
		long mid = (low + high) >> 1;
		if (number_of_trailing_zeros(mid)>=n)
			{
			    ans = mid ;
			    high = mid;
			}
		else
			low = mid+1;
	}

	return ans;
}

// driver code
int main()
{
	long long n,t;
	cin >> t ;
	while(t--){
    cin >> n ;
	cout << findNum(n) << endl;
	}
}

