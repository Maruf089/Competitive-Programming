#include <iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

int main() {
    int t,i=0;
    scanf("%d",&t);
    long long int n,k;
    while(t--)
    {
        long long int res=1;
        scanf("%lld%lld",&n,&k);
        if( n-k < (k-1))//Its IMPORTANT! to get accepted
        k=n-k+1;//selecting the smaller value
        if(k==1)
        printf("1\n");
        else
        {
             for(i=1;i<=k-1;i++)
            {
            res=res*(n-i)/(i);
       /* Dont do res*((n-i)/(i));divide then multiply
        * but instead do res*(n-i)/(i); Its multiply and divide */
            }
        printf("%lld\n",res);
        }
    }

    return 0;
}
