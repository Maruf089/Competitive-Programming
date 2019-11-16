#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    int s=0,c,n,i,m=0;
    cin>>n;
    getchar();
    getline(cin,a);

    for(i=0;i<n;i++)
    {
        if(a[i]>='A' && a[i]<='Z')
            s++;

        else if(a[i]==' ')
        {
            if(s>m)
                m=s;
                s=0;
        }
    }
    if(m>s)
        cout<<m;
    else
        cout<<s;


}
