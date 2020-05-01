#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define inf 1000000000000000000
using namespace std;
int main ()
{
    int n;
    cin>>n;
    lli a[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<lli> s;
    lli total=0, sum=0;
    for (int i=0; i<n; i++)
    {
        s.push_back(a[i]);
        int sz=s.size();
        total+=a[i];
        while (sz>2 && s[sz-2]>=s[sz-1] && s[sz-2]>=s[sz-3])
        {
            lli next=s[sz-1]+s[sz-3]-s[sz-2];
            for (int j=0; j<3; j++)
            {
                s.pop_back();
            }
            s.push_back(next);
            sz-=2;
        }
    }
    lli sign=1, i=0, j=s.size()-1;
    while (i<=j)
    {
        if (s[i]>=s[j])
        {
            sum+=sign*s[i];
            i++;
        }
        else
        {
            sum+=sign*s[j];
            j--;
        }
        sign*=-1;
    }
    cout<<(total+sum)/2<<endl;
    return 0;
}
