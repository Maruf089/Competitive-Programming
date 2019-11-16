#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j=0,h,k,l,l1,Swap;
    char s[101];
    char b[101];
    cin>>s;
    l=strlen(s);
    j=0;
    for(i=0;i<l;i+=2)
    {
        b[j]=s[i];
        j++;
    }
    b[j]='\0';

    l1=strlen(b);

    for(h=0;h<l1-1;h++)
    {
        for(k=0;k<l1-h-1;k++)
        {
            if(b[k]>b[k+1])
               {
                   Swap=b[k];
                    b[k]=b[k+1];
                    b[k+1]=Swap;
                }
        }

    }
    if(l1!=1)
    {
    for(h=0;h<l1;h++)
    {
    cout<<b[h];
    if(b[h+1]!='\0')
    cout<<"+";
    }
    }
    else
        cout<<b[0];

}
