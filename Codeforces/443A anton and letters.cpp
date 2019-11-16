#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main()
{
    char a[1001],b[1001];
    gets(a);
    int j=0,c=0;
    if(strlen(a)==2)
    {
        cout<<"0";
        return 0;
    }
    else if(strlen(a)==3 && a[1]==' ')
    {
        cout<<"0";
        return 0;
    }

    for(int i=1;i<strlen(a);i=i+3)
    {
        b[j]=a[i];
        j++;
    }
    b[j]='\0';

    int l1=strlen(b),Swap;
    for(int h=0;h<l1-1;h++)
    {
        for(int k=0;k<l1-h-1;k++)
        {
            if(b[k]>b[k+1])
               {
                   Swap=b[k];
                    b[k]=b[k+1];
                    b[k+1]=Swap;
                }
        }

    }

    for(int t=0;t<l1;t++)
    {
        if(b[t]!=b[t+1])c++;
    }
    cout<<c;
}
