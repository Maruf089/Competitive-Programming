#include <bits/stdc++.h>
using namespace std;
vector<int>arr;
void add(int n,int a)
{
    for(int i=0; i<n; i++)
        arr[i]=arr[i]+a;
}
void mul(int n,int a)
{
    for(int i=0; i<n; i++)
        arr[i]=arr[i]*a;
}
void divv(int n,int a)
{
    for(int i=0; i<n; i++)
        arr[i]=arr[i]/a;
}
void sw(int a,int b)
{
    swap(arr[a],arr[b]);
}
void rev()
{
    reverse(arr.begin(),arr.end());
}
int main()
{
    int t,l=1;
    char c;
    cin>>t;
    while(t--)
    {
        int n,m,p,a,b,i;
        scanf("%d %d",&n,&m);
        for(i=0; i<n; i++)
        {
            scanf("%d",&p);
            arr.push_back(p);
        }
        for(i=1; i<=m; i++)
        {
            cin>>c;
            if(c=='S')
            {
                scanf("%d",&a);
                add(n,a);
            }
            else if(c=='D')
            {
                scanf("%d",&a);
                divv(n,a);
            }
            else if(c=='M')
            {
                scanf("%d",&a);
                mul(n,a);
            }
            else if(c=='R')
            {
                rev();
            }
            else
            {
                scanf("%d %d",&a,&b);
                sw(a,b);
            }
        }
        printf("Case %d:\n",l);
        for(i=0; i<n; i++)
        {
            printf("%d",arr[i]);
            if(i!=(n-1))
                printf(" ");
        }
        printf("\n");
        l++;
        arr.clear();
    }
    return 0;
}
