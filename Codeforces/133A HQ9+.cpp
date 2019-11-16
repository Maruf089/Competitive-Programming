#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    int i,n;
    cin>>a;

    for(i=0;i<a.size();i++)
    {
        if(a[i]=='H' || a[i]=='Q' || a[i]=='9')
        {
            cout<<"YES"<<endl;
            return 0;
        }

    }
          cout<<"NO"<<endl;
          return 0;
}
