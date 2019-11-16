#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c=0;
    int a[101],b[101];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int k=0;k<n;k++)
    {
        for(int j=0;j<n;j++)
        {
        if(a[k]==b[j])c++;
        }
    }
    cout<<c;
}
