#include<bits\stdc++.h>
using namespace std;
bool p[1003];
int main()
{
    int val;
    while (scanf ("%d,", &val) != EOF)
        p[val]++;
    bool flag=false;
    for (int i=1,j=1; i<1002; i=++j)
        if (p[i])
        {
            for (j=i; p[j]; j++);
            j--;
            if (!flag) flag=true;
            else cout<<",";
            if (j==i) cout<<i;
            else cout<<i<<"-"<<j;
        }
    return 0;
}
