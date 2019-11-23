#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct Point
{
    double x,y;
}p[55];

double distance(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cross(Point p1, Point p2, Point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
bool cmp(Point a,Point b)
{
    double tot = cross(p[0],a,b);
    if(tot>0)
        return true;
    if(tot<0)
        return false;

    return distance(p[0],a)<distance(p[0],b);
}
int main()
{
    Point p[55];
    int n=0;
    while(cin>>p[n].x>>p[n].y)
        n++;
    sort(p+1,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<"("<<p[i].x<<","<<p[i].y<<")"<<endl;
    }
return 0;

}

