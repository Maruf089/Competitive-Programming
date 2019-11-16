#include<bits/stdc++.h>
using namespace std;
string s,ans;
string sub = "";
map<string,int>mymap;
int main()
{
    int n,i,j,c=0;

    cin>>n;
    cin>>s;


    if( s.size()==2)
    {
        cout<<s<<endl;
        return 0;
    }
    int tmax = 0 ,res = 0 ,temp;

    for( i=0;i<n;i++)
    {
        sub += s[i];
        c++;
        if(c==2)
        {
            mymap[sub]++;
            tmax = max( tmax , mymap[sub] );
            if( tmax > res )
            {
                res = tmax ;
                ans = sub ;
            }
           // cout<<sub<<" "<<mymap[sub]<<" "<<tmax<<endl;
            i--;
            c = 0;
            sub = "";
        }
    }
    cout<<ans<<endl;

    return 0;
}

