#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;

   int c=-1,d=-1,flag=0;

   c=s.find("0000000");
   d=s.find("1111111");

   if(c>=0 && c<=s.length()) flag=1;
   else if(d>=0 && d<=s.length()) flag=1;
   else flag=0;

   if(flag==1) printf("YES");
   else printf("NO");

   return 0;
}

///Another Solution
/*
#include<stdio.h>
#include<string.h>
int main()
{
    int i,count=1,c=1;
    char s[500];
    scanf("%s",s);
    count=1;
    for(i=1; i<strlen(s); i++)
    {
        if(s[i]==s[i-1])
        {
            count++;
            c=1;
            if(count>=7)
            {
                break;
            }
        }
        else
        {
            c++;
            count=1;
        }
    }
    if(count>=7)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
*/
