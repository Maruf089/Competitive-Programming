#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    char a[101];
    char b[101];
    cin>>a>>b;
    strrev(b);
    if(strcmp(b,a)==0)
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
