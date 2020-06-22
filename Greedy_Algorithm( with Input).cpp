#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N ; /// number of task
    cin >> N ;

    int cost_of_task[N+9][N+9];

    /// input cost_matrix;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> cost_of_task[i][j];
        }
    }

    vector<int>robot_number;
    for(int i=0;i<N;i++)
    {
        int Min = INT_MAX ,index = -1;
        for(int j=0;j<N;j++)
        {
            if(cost_of_task[i][j]<=Min)
            {
                Min  =  cost_of_task[i][j] ;
                index = j+1 ;
            }
        }
        robot_number.push_back(index);
    }
    for(int i=1;i<=N;i++)
    {
        cout << "For task " << i << " - assigned robot number is " << robot_number[i-1] << endl;
    }

}
