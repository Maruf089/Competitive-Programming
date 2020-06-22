#include<bits/stdc++.h>
using namespace std;

int main()
{
    /// input number of Task
    int Total_task = 5 ;
    int Total_robot_number = 5 ;

    /// create cost matrix for every task

    int cost_for_task_1[] = {10,7,12,15,8};
    int cost_for_task_2[] = {9,7,5,2,8};
    int cost_for_task_3[] = {5,7,9,8,2};
    int cost_for_task_4[] = {14,37,32,35,38};
    int cost_for_task_5[] = {48,47,42,45,48};

    int Min = INT_MAX , index = -1;
    for(int i=0;i<Total_task;i++)
    {
        if(cost_for_task_1[i]<=Min)
        {
            index = i+1;
            Min = cost_for_task_1[i];
        }
    }
    cout << "For task 1 - assigned robot number is " << index << endl;

    Min = INT_MAX , index = -1;
    for(int i=0;i<Total_task;i++)
    {
        if(cost_for_task_2[i]<=Min)
        {
            index = i+1;
            Min = cost_for_task_2[i];
        }
    }
    cout << "For task 2 - assigned robot number is " << index << endl;

    Min = INT_MAX , index = -1;
    for(int i=0;i<Total_task;i++)
    {
        if(cost_for_task_3[i]<=Min)
        {
            index = i+1;
            Min = cost_for_task_3[i];
        }
    }
    cout << "For task 3 - assigned robot number is " << index << endl;

    Min = INT_MAX , index = -1;
    for(int i=0;i<Total_task;i++)
    {
        if(cost_for_task_4[i]<=Min)
        {
            index = i+1;
            Min = cost_for_task_4[i];
        }
    }
    cout << "For task 4 - assigned robot number is " << index << endl;

    Min = INT_MAX , index = -1;
    for(int i=0;i<Total_task;i++)
    {
        if(cost_for_task_5[i]<=Min)
        {
            index = i+1;
            Min = cost_for_task_5[i];
        }
    }
    cout << "For task 5 - assigned robot number is " << index << endl;
}
