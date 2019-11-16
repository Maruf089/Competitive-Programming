
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,m=0;
    int n,i;
    cin>>n;
    for(i=1; i<=n; i++)
    {

        m=0;
        cin>>a>>b>>c;
        m=max(a,b);
        m=max(m,c);
        if(m==c){

        if(c*c == a*a+b*b)
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);
        }
        else if(m==a)
        {
            if(a*a == c*c+b*b)
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);
        }
        else
        {
            if(b*b == a*a+c*c)
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);
        }
    }

    return 0;
}
