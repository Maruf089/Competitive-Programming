#include <iostream>
#include <algorithm>
using namespace std;

long long n,m,s;
long long k;

struct song{
    long long a;
    long long b;
};

song v[100001];

bool compara(song x, song y)
{
    return (x.a-x.b)<(y.a-y.b);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        {
            cin>>v[i].a>>v[i].b;
            s=s+v[i].a;
        }
    sort(v+1,v+n+1,compara);

    cout<< endl ;
    for(int i=n; i>=1; i--)
        cout<<v[i].a<<" "<<v[i].b<<endl;
    cout<< endl ;

    for(int i=n; i>=1 && s>m; i--)
        {
            s=s-v[i].a+v[i].b;
            k++;
        }
    if(s>m)
        cout<<-1;
    else
        cout<<k;
    return 0;
}
