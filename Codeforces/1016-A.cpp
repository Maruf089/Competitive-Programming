#include<bits/stdc++.h>
#define endl '\n'

#define PI acos(-1)
#define ll long long int
#define ull unsigned long long


#define lp(loop,start,end) for(ll loop=start;loop<end;loop++)
#define lpd(loop,start,end) for(ll loop=end;loop>start;loop--)

#define D(x) cout<< #x " = "<<x<<endl
#define cout(case)   cout << "Case " << ++cs << ": " ;


using namespace std;
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout)

string s,s1;
long long n,m,a,b,i,j,t,cs=0,counT=0,k,l=0,temp=0,sum=0,Max,Min,num;


int main()
{
    cin>>n>>m;
long arr[n+5] , brr[n+5] ;

    arr[0] = brr[0] = 0 ;
    lp(i,1,n+1)
    cin>>arr[i],temp += arr[i] , brr[i] = temp/m ;
///D(arr[i]) ;

    lp(i,1,n+1)
        cout<<brr[i]-brr[i-1]<<" ";

}



