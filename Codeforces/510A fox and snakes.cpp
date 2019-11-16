#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,i,j;
    cin>>n>>m;

        for(j=0;j<n;j++)
        {

            if(j==1 || j==5 || j==9 || j==13 || j==17 || j==21 || j==25 || j==29 || j==33 || j==37 || j==41 || j==45 || j==49)
            {
                for(i=1; i<=(m-1); i++)
                {
                    cout<<".";
                }
                cout<<"#"<<endl;
            }

            else if(j==3 || j==7 || j==11 || j==15 || j==19 || j==23 || j==27 || j==31 || j==35 || j==39 || j==43 || j==47)
            {
                cout<<"#";
                 for(i=1; i<=(m-1); i++)
                {
                    cout<<".";
                }
                cout<<endl;
            }

            else if(j==0 || j%2==0)
            {
              for(i=1; i<=m; i++)
                {
                    cout<<"#";
                }
                cout<<endl;
            }
        }
}
