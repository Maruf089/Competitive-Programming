#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define MAX 2000
#define MAX1 500000
using namespace std;
long par[MAX],n,cost1;
struct node
{
    long node1;
    long node2;
    double cost;
};
node arr[MAX1];
struct cor
{
    long  ux;
    long  uy;
};
cor mat[MAX1];
bool comp(node x,node y)
{
    return x.cost<y.cost;
}
void make_set()
{
    long i;
    for(i=0; i<n; i++)
    {
        par[i]=i;
    }
}
long find_set(long n)
{
    if(par[n]!=n)
    {
        par[n]=find_set(par[n]);
    }
    return par[n];
}
int main()
{

    long int test,i,j,c,xx,yy,state,cas=0,road1,rail1;
    double px,py,road,rail;
    scanf("%ld",&test);
    while(test--)
    {
        cas++;
        scanf("%ld %ld",&n,&cost1);
        make_set();
        for(i=0; i<n; i++)
        {
           scanf("%ld %ld",&mat[i].ux,&mat[i].uy);
        }
        c=0;
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                px= (double)(pow((mat[i].ux-mat[j].ux),2));
                py= (double)(pow((mat[i].uy-mat[j].uy),2));
                arr[c].cost=sqrt(px+py);
                arr[c].node1=i;
                arr[c].node2=j;
                c++;
            }
        }
        sort(arr,arr+c,comp);
        state=1;
        rail=0;
        road=0;
        for(i=0; i<c; i++)
        {
            xx=find_set(arr[i].node1);
            yy=find_set(arr[i].node2);
            if(xx!=yy && arr[i].cost>cost1)
            {
                par[xx]=yy;
                rail+=arr[i].cost;
                state++;
            }
            else if(xx!=yy)
            {
                par[xx]=yy;
                road+=arr[i].cost;
            }
        }
        road1=floor(road+.5);
        rail1=floor(rail+.5);
        printf("Case #%ld: %ld %ld %ld\n",cas,state,road1,rail1);
    }
}
