
/**Bismillahir Rahmanir Rahim.**/

#include<bits/stdc++.h>
#define ln '\n'
#define sf scanf
#define pf printf
#define NL printf("\n")
#define SP printf(" ")


#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))
#define _case cout<<"Case "<<++cs<<": "
#define lp(loop,start,end) for(ll loop=start;loop<=end;loop++)
#define lpd(loop,start,end) for(ll loop=end;loop>=start;loop--)

#define D(x) cout<< #x " = "<<x<<endl
#define cout(case)   cout << "Case " << ++cs << ": " ;
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)


#define PI acos(-1)
#define ll long long int
#define ull unsigned long long

#define vi vector <int>
#define vll vector <ll>
#define vs vector <string>
#define pb push_back
#define mpii map <int,int>
#define mpsi map <string,int>
#define mpll map <long long,long long>
#define MP make_pair
#define F first
#define S second

#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b)))

#define INF 10^18
#define MOD 1000000007
#define countv(v,a) count(v.begin(),v.end(),a)
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define uniq(v) v.resize( unique(all(v)) - v.begin())


#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())

#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout)

int dx[] = { 0, 0, 1, -1 }; /// 4 Direction
int dy[] = { 1, -1, 0, 0 };

/// int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
/// int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
/// int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int i, j, k, sum = 0, count;
	int tc, t, d = 0, x, y, n, m, p, value;
	char ch, str[1000];
	bool flag;
	int x1[102], x2[102], y1[102], y2[102], z1[102], z2[102];

	scanf("%d", &tc);
    for(t = 1; t <= tc; t++)
    {
            scanf("%d", &n);

            for(i = 0; i < n; i++)
                    scanf("%d %d %d %d %d %d", &x1[i], &y1[i], &z1[i], &x2[i], &y2[i], &z2[i]);

            int xLow = 0, yLow = 0, zLow = 0;
			int xHigh = 1001, yHigh = 1001, zHigh = 1001;

			for(i = 0; i < n; i++)
			{
				xLow = max(xLow, x1[i]);
				xHigh=  min(xHigh, x2[i]);
				yLow = max(yLow, y1[i]);
				yHigh = min(yHigh, y2[i]);
				zLow = max(zLow, z1[i]);
				zHigh = min(zHigh, z2[i]);
			}

			int volume = (xHigh-xLow) * (yHigh-yLow) * (zHigh-zLow);

			printf("Case %d: %d\n", t, volume < 0 ? 0 : volume);

    }


}
