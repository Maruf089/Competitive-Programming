#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll k,n;
	cin>>k;
	while(k){
		k--;
		cin>>n;
	string s,t;
	cin>>s>>t;
	vector<pair<ll,ll> > v;
	int flag=1;
	for(int i=0;i+1<s.length();i++)
	{
		int j;
		if(s[i]!=t[i]){
		for(j=i+1;j<s.length();j++)
			{
				if(s[j]!=t[j]){
					if(s[j]==s[i])
					{
						v.push_back(make_pair(j,i));
						swap(t[i],s[j]);
						break;
					}
					else if(s[i]==t[j])
					{
						swap(s[j],t[j]);
						swap(t[i],s[j]);
						v.push_back(make_pair(j,j));
						v.push_back(make_pair(j,i));
						break;
					}



				}
			}
			if(j==s.length())
			{
				flag=0;
				break;
			}
		}
	}
	if(flag&&s[s.length()-1]==t[t.length()-1])
	{
		cout<<"Yes"<<endl;
	}
	else
		cout<<"No"<<endl;
}
}
