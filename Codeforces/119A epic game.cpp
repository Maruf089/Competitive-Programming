#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b);

int main()
{
    int a,b,n,i,j,k;
    cin>>a>>b>>n;
    while (1)
    {
        n -= gcd(a, n);
        if (n == 0)
        {
            cout <<"0"<< endl;
            break;
        }
        n -= gcd(b, n);
        if (n == 0)
        {
            cout <<"1"<< endl;
            break;
        }
    }

    return 0;

}
int gcd(int a,int b)
{
    int r;
    r=__gcd(a,b);

    return r;
}


