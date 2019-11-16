#include<iostream>
using namespace std;

int main()
{
    int t,c=0;
    char a[100];
    cin>>t;
    cin>>a;
    for(int i=0;i<t;i++)
    {
        if(a[i]==a[i+1])c++;
    }
    cout<<c<<endl;

}
