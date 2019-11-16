#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,Max,Min,d;
    cin>>a>>b;
    Min=min(a,b);
    Max=max(a,b);
    cout<<Min<<" ";
    d=(Max-Min)/2;

    cout<<d;
}
