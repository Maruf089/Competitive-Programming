#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    char b[100];
    int i,n;
    while(gets(a))
    {

    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='A' && a[i]<='Z')
        {
            a[i]='a'+(a[i]-'A');
        }
    }

    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='A' || a[i]=='a' || a[i]=='y' || a[i]=='u' || a[i]=='o' || a[i]=='i' || a[i]=='e'){continue;}
        else
        {
            printf(".%c",a[i]);
        }
    }
    printf("\n");
    }

}
