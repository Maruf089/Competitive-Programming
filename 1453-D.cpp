#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t ;
    while(t--)
    {
        long long k;
        cin >> k ;
        if(k&1)
            {
                cout << -1 << endl;
                continue;
            }

        long long cur_k = k - 2 ;
        long long tmp = 4;
        long long pow_of_2 = 3 ;
        string Final = "1";

        while(cur_k>0)
        {
            if(cur_k - tmp >= 0)
            {
                Final += '0';
                cur_k -= tmp;
                tmp = (1LL<<pow_of_2);
                pow_of_2++;
            }
            else
            {
                Final += '1';
                tmp = 4;
                cur_k = cur_k - 2;
                pow_of_2 = 3;
            }
        }
        cout << Final.size() << endl;
        for(auto it : Final)
        cout << it << ' ';
        cout << endl;
    }
}

