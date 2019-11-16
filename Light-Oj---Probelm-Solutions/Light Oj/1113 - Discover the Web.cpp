#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t, start, test, i = 0;
    string s;
    string sample[101];
    cin >> t;

    while(t--)
    {
        start = 0, test = 0;

        sample[start] = "http://www.lightoj.com/";

        cout << "Case " << ++i << ":" << endl;

        while(cin >> s)
        {
            if(s == "QUIT")
                break;

            else if(s == "VISIT")
            {
                cin >> s;
                cout << s << endl;

                sample[++test] = s;
                start = test;
            }
            else if(s == "FORWARD")
            {
                if(test + 1 > start)
                    puts("Ignored");

                else
                    cout << sample[++test] << endl;
            }
            else if(s == "BACK")
            {
                if(test - 1 < 0)
                    puts("Ignored");

                else
                    cout << sample[--test] << endl;
            }
        }
    }
    return 0;
}
