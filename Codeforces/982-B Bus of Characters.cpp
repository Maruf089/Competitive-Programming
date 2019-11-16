#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    string s;
    pair<int,int>mypair[200001];
    priority_queue< pair<int,int> >pq;

    for(i=0;i<n;i++)
    {
        cin>>mypair[i].first;
        mypair[i].second = i+1;
    }
     cin>>s;
     sort(mypair,mypair+n);
     int k=0;
     for(i=0;i<2*n;i++)
     {
         if(s[i]=='0')
         {
             cout<<mypair[k].second<<" ";
             pq.push(mypair[k]);
             k++;
         }
         else
         {
             cout<<pq.top().second<<" ";
             pq.pop();
         }
     }


}
