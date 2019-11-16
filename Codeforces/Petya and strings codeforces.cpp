#include<bits/stdc++.h>
using namespace std;

int main()
{
   string a;
   string b;
   cin>>a;
   cin>>b;

        for(int i=0;i<a.length();i++)
        {
            if(a[i]>='a' && a[i]<='z')
            a[i]='A'+(a[i]-'a');
        }
         for(int i=0;i<b.length();i++)
         {

            if(b[i]>='a' && b[i]<='z')
                b[i]='A'+(b[i]-'a');
        }

        if(a<b)cout<<"-1"<<endl;

        else if(a==b)cout<<"0"<<endl;
        else
            cout<<"1"<<endl;
            return 0;
}
