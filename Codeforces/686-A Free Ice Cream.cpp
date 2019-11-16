#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n,x;
	cin >> n >> x;

	long long current = x;
	int distressed = 0;

	for (int i = 0; i < n; ++i)
	{
		char sign;
		long long value;
		cin >> sign >> value;
		if (sign == '+')
		{
			current += value;
		}
		else
		{
			if (value <= current) current -= value;
			else distressed++;
		}
	}

	cout << current << " " << distressed;

}
