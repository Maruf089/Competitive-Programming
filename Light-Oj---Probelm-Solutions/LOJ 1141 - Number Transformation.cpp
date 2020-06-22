#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef int in ;
typedef unsigned long long ull ;
const double pi = 2*acos(0) ;
#define maxi 40000
#define pf printf
#define sc scanf
#define pb push_back
#define MEM(x,y) (memset((x),(y),sizeof(x)))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define load(array,size)  for(int i=0 ; i<size ; i++) cin>>array[i]  ;
#define new_line  pf("\n")
#define clear_data(array) memset(array,0,sizeof(array))
#define highest_int 2147483647
#define sz 1000+10

bool prime[100001] ;
vector<int> data ;
vector<int> prime_fact[100001] ;


void isPrime()
{
    memset(prime,true,sizeof(prime)) ;

    for(int i =2 ; i<=sz ; i++)
    {
        for(int j= 2*i ; j<=sz ; j+=i)
        {
            prime[j] =false ;
        }
    }

    for(int i=2 ; i<=sz ; i++)
    {
        if(prime[i])
            data.pb(i) ;
    }
}

void fact()
{
    for(int i=2 ; i<=sz ; i++)
    {
        for(int j=0 ; j<data.size() ; j++)
        {
            if(i%data[j]==0 && i>data[j])
                prime_fact[i].pb(data[j]) ;
        }
    }
}

int dis[100001] ;

int bfs(int s, int t)
{
    bool visited[100001] ;
    memset(visited,false,sizeof(visited)) ;
    queue<int>q  ;
    memset(dis,0,sizeof(dis)) ;

    q.push(s) ;
    dis[s] =0 ;
    while(!q.empty())
    {
        int u = q.front() ;
        q.pop() ;
        if(u==t)
            return dis[u] ;
        for(int i=0 ; i<prime_fact[u].size() ; i++)
        {
            int v = u+ prime_fact[u][i] ;
            if(visited[v]==false && v<=t)
            {
                visited[v] = true ;
                q.push(v) ;
                dis[v] = dis[u] +1 ;
            }
        }
    }
    return -1 ;

}
int main()
{
    isPrime() ;
    fact() ;
    int test ;
    cin>>test ;
    int cnt =1 ;
    while(test--)
    {
        int s,t ;
        cin>>s>>t ;
        int ans = bfs(s,t) ;
        pf("Case %d: %d\n",cnt++,ans) ;
    }
    return 0;
}
