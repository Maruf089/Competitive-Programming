#include <bits/stdc++.h>

using namespace std;

#define vlong long long
#define xx first
#define yy second
#define N 100005
#define MOD 1000000007
#define dbg(x) cout<<#x " = "<<(x)<<endl
#define read freopen("in.txt","r",stdin)

//int dx[]={1,0,-1,0};                  int dy[]={0,1,0,-1};                // 4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};        int dy[]={0,1,1,1,0,-1,-1,-1};      // 8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};       int dy[]={1,2,2,1,-1,-2,-2,-1};     // Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};         int dy[]={-1,+1,+2,+1,-1,-2};       // Hexagonal Direction

int setBit(int n,int pos)
{
    return n|(1<<pos);
}
int resetBit(int n,int pos)
{
    return n&~(1<<pos);
}
bool checkBit(int n,int pos)
{
    return n&(1<<pos);
}
inline vlong bigmod(vlong p,vlong e,vlong M)
{
    vlong ret=1;
    while(e>0)
    {
        if(e%2)
            ret=(ret*p)%M;
        p=(p*p)%M;
        e/=2;
    }
    return ret;
}
inline vlong power(vlong x,vlong y)
{
    vlong ans=1;
    while(y>0)
    {
        if(y%2)
            ans*=x;
        x*=x;
        y/=2;
    }
    return ans;
}
template<class T> T gcd(T a,T b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
template<class T> T lcm(T a,T b)
{
    return a*(b/gcd(a,b));
}

int n,a[N],t[N*3];

void build(int num,int st,int ed)
{
    if(st==ed)
    {
        t[num]=1;
        return;
    }
    int mid=(st+ed)>>1;
    build(num<<1,st,mid);
    build(num<<1|1,mid+1,ed);
    t[num]=t[num<<1]+t[num<<1|1];
}

void update(int num,int st,int ed,int in,int v)
{
    if(st==ed)
    {
        t[num]=v;
        return;
    }
    int mid=(st+ed)>>1;
    if(in<=t[num<<1])
    {
        update(num<<1,st,mid,in,v);
    }
    else
    {
        update(num<<1|1,mid+1,ed,in-t[num<<1],v);
    }
    t[num]=t[num<<1]+t[num<<1|1];
}

int query(int num,int st,int ed,int in)
{
    if(st==ed)
    {
        return st;
    }
    int mid=(st+ed)>>1;
    if(in<=t[num<<1])
    {
        return query(num<<1,st,mid,in);
    }
    else
    {
        return query(num<<1|1,mid+1,ed,in-t[num<<1]);
    }
}

int main()
{
    int tc,tt=0;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        memset(t,0,sizeof t);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",a+i);
        }
        build(1,1,n);
        for(int i=n; i>1; i--)
        {
            update(1,1,n,i-a[i],0);
        }
        printf("Case %d: %d\n",++tt,query(1,1,n,1));
    }
}
