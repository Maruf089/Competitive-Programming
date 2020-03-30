#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define nl "\n"
#define fout(x) fixed<<setprecision(x)
#define one(x) __builtin_popcountll(x)
#define F first
#define S second

void __print(int x)
{
    cerr << x;
}
void __print(long x)
{
    cerr << x;
}
void __print(long long x)
{
    cerr << x;
}
void __print(unsigned x)
{
    cerr << x;
}
void __print(unsigned long x)
{
    cerr << x;
}
void __print(unsigned long long x)
{
    cerr << x;
}
void __print(float x)
{
    cerr << fout(10)<<x;
}
void __print(double x)
{
    cerr << fout(10)<<x;
}
void __print(long double x)
{
    cerr << fout(10)<<x;
}
void __print(char x)
{
    cerr << '\'' << x << '\'';
}
void __print(const char *x)
{
    cerr << '\"' << x << '\"';
}
void __print(const string &x)
{
    cerr << '\"' << x << '\"';
}
void __print(bool x)
{
    cerr << (x ? "true" : "false");
}
template<typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template<typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i: x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print()
{
    cerr << "]\n";
}
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int mod=1e9+7;
const double eps=1e-9;
const double PI=acos(-1.0);

// ****************************************************

int arr[100010];
int cnt[100010], v[100010];
bool vis[100010];

int main()
{
    int tc;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int zero=-1, last=-1;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
                zero=i;
            if(arr[i]==q)
                last=1;
            cnt[arr[i]]++;
        }
        int ans=1;
        stack<int>st;
        st.push(-1);
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
                v[i]=st.top();
            else
            {
                if(arr[i]<st.top())
                {
                    ans=-1;
                    break;
                }
                if(cnt[arr[i]]>1)
                {
                    st.push(arr[i]);
                    cnt[arr[i]]--;
                    v[i]=st.top();
                }
                else
                {
                    v[i]=arr[i];
                    while(!st.empty() && st.top()==arr[i])
                        st.pop();
                }
            }
        }
        if(last==-1 && zero==-1)
            ans=-1;
        if(last==-1 && zero>=0)
        {
            v[zero] = q;
        }
        if(ans==1)
        {
            printf("Case %d: YES\n", cs);
            for(int i=0; i<n; i++)
            {
                if(v[i]==-1 || v[i]==0)
                    v[i]=1;
            }
            printf("%d", v[0]);
            for(int i=1; i<n; i++)
            {
                printf(" %d", v[i]);
            }
            printf("\n");
        }
        else
            printf("Case %d: NO\n", cs);
        mem(cnt, 0);
    }
    return 0;
}
