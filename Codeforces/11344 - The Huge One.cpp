#include<bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a)  a.begin(), a.end()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define mx  550
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define NOT_VISITED 0
#define IS_VISITED 1



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};


const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;

char s[1005];
int n,arr[15];

int main()
{
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;

    sf(t);



    TEST_CASE(t)
    {
        getchar();
        gets(s);
        sf(n);

        for(int i=0; i<n ; i++)
            sf(arr[i]);

        bool f=false;
        int len=strlen(s);

        int rem=0;
        for(int i=0 ; i<n ; i++)
        {
            rem=0;
            for(int j=0 ; j<len ; j++)
            {

                rem = (rem * 10 + (s[j] - '0')) % arr[i];
            }
            if(rem)
            {
                f=true;
                break;
            }
        }
        if (f)
            printf("%s - Simple.\n", s);
        else
            printf("%s - Wonderful.\n", s);
        f=false;

    }

    return 0;
}
