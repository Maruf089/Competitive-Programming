#include<stdio.h>
#include<string.h>
int main()
{
int a,b,c,d,e;
char m[100];
while(scanf("%s",m)!=EOF){
a=strlen(m);
for(d=0;d<a;d++){
if(m[d]=='A' || m[d]=='B' || m[d]=='C')
m[d]='2';
else if(m[d]=='D' || m[d]=='E' || m[d]=='F')
m[d]='3';
else if(m[d]=='G' || m[d]=='H' || m[d]=='I')
m[d]='4';
else if(m[d]=='J' || m[d]=='K' || m[d]=='L')
m[d]='5';
else if(m[d]=='M' || m[d]=='N' || m[d]=='O')
m[d]='6';
else if(m[d]=='P' || m[d]=='Q' || m[d]=='R' || m[d]=='S')
m[d]='7';
else if(m[d]=='T' || m[d]=='U' || m[d]=='V')
m[d]='8';
else if(m[d]=='W' || m[d]=='X' || m[d]=='Y' || m[d]=='Z')
m[d]='9';
else
m[d]=m[d];
}
printf("%s\n",m);
}
return 0;
}
