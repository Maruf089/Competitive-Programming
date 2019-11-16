#include<bits/stdc++.h>
using namespace std;

string word;
map<string,int>mymap;

string func( string x )
{
    string temp = "";

    for(char ch='a'; ch<='z';ch++)
    {
        for(int j = 0; j<x.size(); j++)
        {
            if( x[j] == ch )
            {
                temp += x[j] ;
                break;
            }
        }
    }
    return temp;
}
int main()
{
    int n;
    cin>>n;

    while( n-- )
    {
        cin>>word;
        mymap[func(word)]++;
    }
    cout<<mymap.size();

}

