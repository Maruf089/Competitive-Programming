#include<bits/stdc++.h>
using namespace std;

int f(int y,int qy)
{
   int i,j,c=0;
  for(i=y+1;i<=qy;i++)
  {

  if(i%400 == 0)
    c++;
   else if(i%100 ==0)
    ;
  else if(i%4 ==0)
    c++;
    else
        ;
  }
  return c;

}
int main()
{
    int t,d,m,y,qy,i,j,p=0;

    cin>>t;
    for(i=1;i<=t;i++)
    {
        p=0;
        cin>>d>>m>>y>>qy;

        if(d == 29 && m==2)
           {
               p=f(y,qy);
           }
        else
            p=qy-y;

        cout<<"Case "<<i<<": "<<p<<endl;
    }
}
