#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,c,sum;
    int s=0;
    getline(cin,a);
        getline(cin,b);
            getline(cin,c);
    sum=a+b;
    sort(sum.begin(),sum.end());
    sort(c.begin(),c.end());

    if(sum==c)
        cout<<"YES";
    else
        cout<<"NO";

}
