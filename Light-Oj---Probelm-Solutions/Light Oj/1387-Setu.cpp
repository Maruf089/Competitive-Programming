#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int nCase,tCase;
    cin >> nCase;
    for(tCase=1; tCase<=nCase; tCase++)
    {
        int i,n,sum=0;
        cin >> n;
        printf("Case %d:\n",tCase);
        for(i=0; i<n; i++)
        {
            int k;
            string s[102];
            cin>>s[i];
            if(s[i]=="donate")
            {
                cin>>k;
                sum=sum+k;
            }
            if(s[i]=="report")
            {
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}

