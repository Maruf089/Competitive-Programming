#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,m,i,j,s=0,c=0;
    cin>>n>>m;

    while(m--)
    {
        int temp = n % 10;
        if(temp != 0)
            n--;
        else
            n/=10;
    }
    cout<<n<<endl;
}
