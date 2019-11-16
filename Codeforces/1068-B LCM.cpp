#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,n,c=0;

    cin >> n;

    for(i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
            {
                if(n/i==i)
                    c++;
                else
                    c+=2;
            }
    }
    cout << c;
}
