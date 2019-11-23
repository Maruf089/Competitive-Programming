#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 1001;
typedef struct point
{
    double x, y;
    point()
    {

    }
    point(double a, double b)
    {
        x = a;
        y = b;
    }
    point operator -(const point &b) const
    {
        return point(x - b.x, y - b.x);
    }
    double operator *(const point &b)const
    {
        return x*b.x + y*b.y;
    }
} point;
point p[maxn];
int n=0, res[maxn];
int top;
bool cmp(point a, point b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}
bool multi(point p1, point p2, point p0)
{
    return (p1.x - p0.x)*(p2.y - p0.y) >= (p2.x - p0.x)*(p1.y - p0.y);
}
void Graham()
{
    int i, len;
    sort(p, p + n, cmp);
    top = 1;

    if (n == 0)
        return;
    res[0] = 0;
    if (n == 1)
        return;
    res[1] = 1;
    if (n == 2)
        return;
    res[2] = 2;
    for (i = 2;  i < n; i++)
    {
        while (top&&multi(p[i], p[res[top]], p[res[top - 1]]))
            top--;
        res[++top] = i;
    }
    len = top;
    res[++top] = n - 2;
    for (i = n - 3; i >= 0; i--)
    {
        while (top!=len&&multi(p[i], p[res[top]], p[res[top - 1]]))
            top--;
        res[++top] = i;
    }
}
int main(void)
{
    int i, s;
    while (scanf("%lf%lf", &p[n].x, &p[n].y)!=EOF)
        n++;
    Graham();
    for (s = 0; s < top; s++)
    {
        if (!p[res[s]].x && !p[res[s]].y)
            break;
    }
    for (i = s; i < top; i++)
    {
        printf("(%.lf,%.lf)\n",p[res[i]].x, p[res[i]].y);
    }
    for (i = 0; i < s; i++)
    {
        printf("(%.lf,%.lf)\n", p[res[i]].x, p[res[i]].y);
    }
    return 0;
}
