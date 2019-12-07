/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
#define pf printf
#define sf scanf
#define inp(x) scanf("%lld",&x)
#define inp2(a,b) scanf("%lld %lld",&a,&b)

#define D(x) cerr<< #x " = "<<x<<endl
#define dbg(x) cerr << #x << " = " << x << endl;
#define D2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;

string s,s1;
int n,m,a,b,i,j,d,t,cs=0,counT=0,k,sum1=0,sum=0,Min,num;
int main()
{

    cin >> t;
    while(t--)
    {
        cin >> n >>  s ;
        map<char,int>mp,mp2,mp3;
        int pos=0,ans = 0 ,pos1=0,flag=0,Min=n+9,idx;
        char ch ;
        for(i=0; i<n; i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]>=2)
            {
                Min = min(Min,i+1-mp2[s[i]]);
                flag = 1 ;
            }
            mp2[s[i]] = i+1;
        }

        if(!flag) /// all are distinct
        {
            cout << 0 << ln ;
        }
        else
        {
            cout << n-Min << ln ;
        }
    }

}

