#include<bits/stdc++.h>
using namespace std;
map<int,int>mymap;
int main()
{
    int n,i,j,c=0;
    cin>>n;
    int a[n];
    string s;

    for( i=0;i<n;i++)
    {
       cin>>a[i];
       mymap[a[i]]++;
    }
    cout<<mymap.size()<<endl;
    int b[mymap.size()];
    int k = 0;
    for(i=n-1;i>=0;i--)
    {
        if( mymap[a[i]] != 0)
        {
             b[k] = a[i];
             //cout<<b[k]<<endl;
             k++;
            mymap[a[i]] = 0 ;
        }
    }
    reverse(b,b+k);
    for(int i=0;i<k;i++){
        cout<<b[i]<<" ";
    }

}

