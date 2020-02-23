#include<bits/stdc++.h>
using namespace std;
/// You are given two numbers n and k. Find the largest power of k such that n! is divisible by k^x
int find_pow(int n,int k)
{
    int res = 0 ;
    while(n)
    {
        n/=k;
        res += n ;
    }
    return res ;
}
int main()
{
    int n,k;
    cin >> n >> k ;
    cout << find_pow(n,k) << endl;
}
