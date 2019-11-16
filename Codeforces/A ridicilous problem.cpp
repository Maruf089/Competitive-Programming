/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
#define ln '\n'
#define D(x) cout<< #x " = "<<x<<endl
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define _case cout<<"Case "<<++cs<<": "

#define MOD 1000000007
#define countv(v,a) count(v.begin(),v.end(),a)
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define uniq(v) v.resize( unique(all(v)) - v.begin())

#define PI acos(-1)
#define ll long long int
#define ull unsigned long long

#define vi vector <int>
#define vll vector <ll>
#define vs vector <string>
#define pb push_back
#define eb emplace_back
#define mpii map <int,int>
#define mpsi map <string,int>
#define mpll map <long long,long long>
#define MP make_pair
#define F first
#define S second

#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) (a*(b/__gcd(a,b)))

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())

#define all(v) v.begin(),v.end()
#define MEM(a, b) memset(a, b, sizeof(a))

#define fast ios_base::sync_with_stdio(false)
using namespace std;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9;
const int inf = 0x3f3f3f3f;
/// count set bit C = (num * 0x200040008001ULL & 0x111111111111111ULL) % 0xf; /// 32 bit integer

/*------------------------------Graph Moves----------------------------*/
//Rotation: S -> E -> N -> W
//const int fx[] = {0, +1, 0, -1};
//const int fy[] = {-1, 0, +1, 0};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

//Bit Operations
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i); }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }


inline bool isSquare(ll x)  { ll s = sqrt(x); return (s*s==x); }
inline bool isFib(ll x) { return isSquare(5*x*x+4)|| isSquare(5*x*x-4); }
inline bool isPowerOfTwo(ll x)   { return ((1LL<<(ll)log2(x))==x); }

typedef struct {
    double x,y;
   /// Point() {}
  ///  Point(double x,double y) : x(x), y(y) {}
} Point;

double distance(Point a , Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

string grid[9];

int main()
{
    int i,l;
    for(i=1;i<8;i++)
    {
        cin >> grid[i];
    }
    l=grid[1].size();
    for(i=0;i<l;i+=6)
    {
        if(grid[1][i] == '*'  &&  grid[4][i] == '*'  &&  grid[7][i] == '*')
        {
            if(grid[1][i+4] == '*'  &&  grid[4][i+4] == '*'  &&  grid[7][i+4] == '*')
            {
                if(grid[4][i+1] == '*')         cout << 'H';
                else if(grid[2][i+1] == '*')    cout << 'M';
                else                            cout << 'N';
            }
            else if(grid[1][i+1] == '.')
            {
                if(grid[4][i+1] == '*')         cout << 'K';
                else                            cout << 'L';
            }
            else if(grid[1][i+4] == '*')
            {
                if(grid[7][i+4] == '*')         cout << 'E';
                else                            cout << 'F';
            }
            else if(grid[7][i+1] == '*')
            {
                if(grid[4][i+1] == '*')         cout << 'B';
                else                            cout << 'D';
            }
            else
            {
                if(grid[7][i+4] == '*')         cout << 'R';
                else                            cout << 'P';
            }
        }
        else if(grid[7][i] == '*')
        {
            if(grid[4][i+1] == '*')
            {
                if(grid[1][i+4] == '*')         cout << 'S';
                else                            cout << 'A';
            }
            else if(grid[3][i+1] == '*')        cout << 'X';
            else                                cout << 'Z';
        }
        else if(grid[6][i+2] == '*')
        {
            if(grid[1][i] == '*'  &&  grid[1][i+4] == '*')
            {
                if(grid[1][i+2] == '*')         cout << 'T';
                else if(grid[7][i+1] == '*')    cout << 'W';
                else                            cout << 'Y';
            }
            else                                cout << 'I';
        }
        else if(grid[2][i] == '*'  &&  grid[2][i+4] == '*')
        {
            if(grid[6][i] == '*'  &&  grid[6][i+4] == '*')
            {
                if(grid[1][i] == '*')           cout << 'U';
                else if(grid[5][i+3] == '*')    cout << 'G';
                else if(grid[4][i+4] == '*')    cout << 'O';
                else                            cout << 'C';
            }
            else
            {
                if(grid[7][i+4] == '*')         cout << 'Q';
                else                            cout << 'V';
            }
        }
        else
        {
                                                cout << 'J';
        }
    }
    return 0;
}
