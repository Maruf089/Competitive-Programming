#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     int a,b,c,sum=0,m,n,o,d,f,g;
     cin>>a>>b>>c;
     m=(a+b)*c;
     g=a*b+c;
     d=a*(b+c);
     n=a+(b*c);
     o=a*b*c;
     f=a+b+c;

     if(m>n && m>o && m>d && m>f && m>g)
        cout<<m;
     else if(m<n && n>o && n>d && n>f && n>g)
        cout<<n;
     else if(o>n && m<o && o>d && o>f && o>g)
        cout<<o;
        else if(f>m && f>n && f>o && f>d && f>g)
        cout<<f;
            else if(g>m && g>n && g>o && g>d && f<g)
            cout<<g;
     else
        cout<<d;
 }
