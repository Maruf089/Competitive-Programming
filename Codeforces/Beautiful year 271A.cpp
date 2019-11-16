#include<bits/stdc++.h>
using namespace std;
int f(int n);

int main()
{
    int n,ans;
    cin>>n;
    n++;

    up:
    ans=f(n);
    if(ans==0)
    {
        cout<<n<<endl;
    }
    else
    {
        n++;
        goto up;
    }

}
int f(int y)
{
    int i,c,j,k,temp;
    int a[101];
    temp=y;
    i=0;
    while(temp!=0){
        a[i]=temp%10;
        temp/=10;
        i++;
    }
    if(a[0]!=a[1] && a[0]!=a[2] && a[0]!=a[3] && a[1]!=a[2] && a[1]!=a[3] && a[2]!=a[3] )
    {
       c=0;
    }
    else
        c=1;

        return c;

}
