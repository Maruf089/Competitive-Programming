#include<bits/stdc++.h>
#define endl '\n'
#define sf scanf
#define pf printf

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

vector<int> a, b;

int main(){

    long long n;

    cin>>n;

    for(int i = 0;i<n;i++){

        int x;
        cin>>x;
        a.push_back(x);

    }

    for(int i = 0;i<n;i++){

        int x;
        cin>>x;
        b.push_back(x);

    }

    long long sa=0, sb=0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 1; i<=2*n;i++){



        if(i%2){

            if(!a.empty() && b.empty()){
                 sa+=a.back();
                 a.pop_back();
            }else if(a.empty() && !b.empty()){

                b.pop_back();

            }else if(a.back() > b.back()){

                sa+=a.back();
                a.pop_back();


            }else{

                b.pop_back();

            }
        }else{

                        if(!b.empty() && a.empty()){
                 sb+=b.back();
                 b.pop_back();
            }else
            if(b.empty() && !a.empty()){

                a.pop_back();

            }else
           if(b.back() > a.back()){

                sb+=b.back();
                b.pop_back();


            }else{

                a.pop_back();

            }

        }

    }
    cout<<sa-sb;


}


