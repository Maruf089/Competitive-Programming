#include<stdio.h>
#include<string.h>
main()
{
    char a[10000];
    int l,i,n;
    while(gets(a))
    {
    if(a[0]>='a' && a[0]<='z')a[0]='A'+(a[0]-'a');
        printf("%s\n",a);
    }
    return 0;
}
