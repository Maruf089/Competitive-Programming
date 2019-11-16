#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mm;
    mm["a"] = mm["e"] = mm["i"] = mm["o"] = mm["u"] = mm["y"] = 1;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0; i<s.size(); ++i)
    {
        if (mm[s.substr(i,1)] && mm[s.substr(i+1,1)])
        {
            s.erase(i + 1, 1);
            --i;
        }

    }
    cout << s ;
}
