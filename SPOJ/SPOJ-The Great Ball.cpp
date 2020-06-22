#include <bits/stdc++.h>
using namespace std;

//FOLD ME
namespace
{
typedef long long LL;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef unsigned long long ULL;

//Macros
int CC_;
#define sf scanf
#define pf printf
#define PP cin.get();
#define NL cout<<endl;
#define all(container) container.begin(),container.end()
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;
#define DM(MT,n_,m_)pf("Matrix %s:\n   ", #MT);for(int i_= 0;i_<m_;i_++)pf("%4d ", i_);NL;NL;for(int r_=0;r_<n_;r_++){pf("%2d ", r_);for(int c_= 0;c_<m_;c_++)pf("%4d ", MT[r_][c_]);NL}
#define mem(a_,b_)(a_, b_, sizeof(a_));

}

const int sss= 1E7;

int a[sss+3];
void solve(void)
{
    int Tc = 1;
    int n, cc;

    sf("%d", &Tc);

    for(int Case= 1; Case<=Tc; Case++)
    {
        sf("%d", &n);

        int mxi= -1;
        int mx= 0;
        memset(a, 0, sizeof a);
        int  u,v;
        for(int i= 0; i<n; i++)
        {
            sf("%d%d", &u,&v);
            a[u]++;
            a[v+1]--;
            mxi= max(mxi, max(u, v));
        }

        for(int i= 1; i<= mxi; i++)
        {
            a[i]+= a[i-1];
            mx= max(mx, a[i]);
        }
        pf("%d\n", (int)mx);
    }

}



int main(void)
{
    solve();
}
