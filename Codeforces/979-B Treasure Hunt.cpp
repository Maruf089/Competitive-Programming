#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int func(int mx,int ss,int n)
{
    if(ss == 1) return 1;

    if(mx == ss)
    {
        if(n == 1) return mx - 1;
        else return mx;
    }
    return min(ss, mx+n);

}
int main()
{
    int n,i,j,c1=1,c2=1,c3=1;
    cin>>n;
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    sort(s3.begin(),s3.end());

    long m1=1,m3=1,m2=1;
    long temp1=1,temp2=1,temp3=1;
  /// part 1
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==s1[i+1])
            c1++;
        else
        {
            if( c1 >= m1 )
            {
                m1 = c1;
                temp1 = i;
            }
            c1=1;
        }
    }
      m1 = func(m1,s1.size(),n);


    /// part 2
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]==s2[i+1])
            c2++;
        else
        {
            if( c2 >= m2 )
            {
                m2 = c2;
                temp2 = i;
            }
            c2=1;
        }
    }
  m2 = func(m2,s2.size(),n);

    /// part  3
        for(int i=0;i<s3.size();i++)
    {
        if(s3[i]==s3[i+1])
            c3++;
        else
        {
            if( c3 >= m3 )
            {
                m3 = c3;
                temp3 = i;
            }
            c3=1;
        }
    }
   m3 = func(m3,s3.size(),n);

   ///cout<<m1<<" "<<m2<<" "<<m3<<endl;
        if( m1>m2 && m1>m3)
                cout<<"Kuro";
        else if( m2>m1 && m2>m3)
                cout<<"Shiro";
        else if( m3>m1 && m3>m2)
            cout<<"Katie";
        else
            cout<<"Draw";

}
