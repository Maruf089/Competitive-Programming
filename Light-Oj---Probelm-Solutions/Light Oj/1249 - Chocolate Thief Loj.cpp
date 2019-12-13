
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student
{
    string name;
    int volume;
};

bool compare(student a,student b)
{
    return a.volume<b.volume;

}
int main()
{

    int t,n,height,width,depth;
    string name;
    cin>>t;
    student st,stThief,stLost;
    for(int i = 0; i < t; i++)
    {
        vector<student> Students;
        cin>>n;
        for(int i = 0; i<n; i++)
        {
            cin>>name>>height>>width>>depth;
            st.name = name;
            st.volume = height*width*depth;
            Students.push_back(st);
        }
        sort(Students.begin(),Students.end(),compare);
        cout<<"Case "<<i+1<<": ";
        stLost = Students[0];
        stThief = Students[n-1];
        if(stThief.volume==stLost.volume)
            cout<<"no thief"<<endl;
        else
            cout<<stThief.name<<" took chocolate from "<<stLost.name<<endl;

    }

}
