#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n, m, k, coins ,l,d;

    cin>>n>>m>>k>>l;

    coins = ceil((k+l)/(long double)m);

    if(k+l > n || coins*m > n)
        cout<<"-1"<<endl;
    else
        cout<<coins<<endl;
}
