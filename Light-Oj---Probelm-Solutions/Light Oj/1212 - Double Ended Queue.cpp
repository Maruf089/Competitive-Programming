#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,t,x,c=0,temp = 0;

    string s;

    deque<int>q1;


    cin>>t;

    for(int i=1; i<=t ; i++)
    {
        cout<<"Case "<<i<<":"<<endl;

        cin>>n>>m;
        q1.clear();

        for( int j=1; j<=m; j++)
        {

            cin>>s;

            if( s == "pushLeft" )
            {

                cin>>x;

                if( q1.size() != n )
                {

                    q1.push_front(x);
                    cout<<"Pushed in left: "<<x<<endl;
                }

                else
                    cout<<"The queue is full"<<endl;

            }

            else if( s == "pushRight" )
            {

                cin>>x;

                if( q1.size() != n )
                {

                    q1.push_back(x);
                    cout<<"Pushed in right: "<<x<<endl;
                }
                else
                    cout<<"The queue is full"<<endl;

            }

            else if( s == "popLeft")
            {
                if( q1.empty() )
                    cout<<"The queue is empty"<<endl;

                else
                {
                    cout<<"Popped from left: "<<q1.front()<<endl;
                    q1.pop_front();
                }
            }

            else if( s == "popRight")
            {
                if( q1.empty() )
                    cout<<"The queue is empty"<<endl;

                else
                {

                    cout<<"Popped from right: "<<q1.back()<<endl;
                    q1.pop_back();

                }
            }


        }

    }

}
