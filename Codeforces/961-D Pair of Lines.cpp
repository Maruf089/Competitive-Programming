#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005

const double eps = 1e-9;
const double pi = acos(-1);

bool Equal(double x, double y)
{
    return  fabs(x-y)<eps; ///x==y
}
bool Greater(double x, double y)
{
    return x-eps>y; ///x>y
}
bool Lesser(double x, double y)
{
    return x+eps<y; ///x<y
}

///Point

struct point
{
    double x, y;
    point()
    {
        x=y=0.0;
    }
    point(double _x, double _y)
    {
        x=_x;
        y=_y;
    }
    bool operator<(point p) const
    {
        if(fabs(x-p.x)>eps) return x<p.x;
        else return y<p.y;
    }
};

///Euclidean distance
double dist(point A, point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

///Rotate P by rad(in radian) CCW w.r.t origin (0, 0)
point pointRotate(point P, double rad)
{
    return point(P.x*cos(rad)-P.y*sin(rad), P.x*sin(rad)+P.y*cos(rad));
}

///Rotate P by rad(in radian) CCW w.r.t origin Q
point pointRotatePoint(point P, point Q, double rad)
{
    point A = pointRotate(point(P.x-Q.x, P.y-Q.y), rad);
    A.x = A.x + Q.x;
    A.y = A.y + Q.y;
    return A;
}

///Line

struct line
{
    double a, b, c;
};

///Point Point Formula
line pointsToLine(point A, point B)
{
    line L;
    if(Equal(A.x,B.x)) ///Vertical Line
    {
        L.a=1;
        L.b=0.0;
        L.c=-A.x;
    }
    else
    {
        L.a=-(A.y-B.y)/(A.x-B.x);
        L.b=1;
        L.c=-(L.a*A.x)-A.y;
    }
    return L;
}

///Two lines are Parallel
bool areParallel(line L1, line L2)
{
    return Equal(L1.a,L2.a)&&Equal(L1.b,L2.b);
}

///Point P is on the line from endpoint A and b
bool onSegment(point P, point A, point B)
{
    return P.x>=min(A.x,B.x) && P.x<=max(A.x,B.x) && P.y>=min(A.y,B.y) && P.y<=max(A.y,B.y);
}

///Two line intersect and P is intersected point
bool doIntersect(point A, point B, point C, point D, point &P)
{
    line L1 = pointsToLine(A,B);
    line L2 = pointsToLine(C,D);
    if(areParallel(L1,L2)) return false;
    P.x = (L2.b*L1.c - L1.b*L2.c) / (L2.a*L1.b - L1.a*L2.b);
    if(fabs(L1.b) > eps) P.y = -(L1.a*P.x+L1.c);
    else P.y = -(L2.a*P.x+L2.c);
    return true;
}

///Vector

struct vec
{
    double x, y;
    vec()
    {
        x=y=0.0;
    }
    vec(double _x, double _y)
    {
        x=_x;
        y=_y;
    }
};

///Convert two points to vector A->B
vec toVector(point A, point B)
{
    return vec(B.x-A.x, B.y-A.y);
}

vec scale(vec v, double s)
{
    return vec(v.x*s,v.y*s);
}

///Translate P according to v
///i.e: P is transferred (from its current position) |v| unit in the direction of v
point translate(point P, vec v)
{
    return point(P.x+v.x, P.y+v.y);
}

///Dot Product of vector A, B
double dotProduct(vec A, vec B)
{
    return A.x*B.x+A.y*B.y;
}

///Using determinant rule
double crossProduct(vec A, vec B)
{
    return A.x*B.y - A.y*B.x;
}

///|v|^2 = v.x*v.x + v.y*v.y
double norm_sq(vec v)
{
    return v.x*v.x + v.y*v.y;
}

///Returns the distance from P to the line(_segment=0)/segment(_segment=1) defined by -
///Two points A and B (A and B must be different for line)
///The closest point (from P to line) is stored in C
double distToLineOrSeg(point P, point A, point B, point &C, bool _segment)
{
    vec AP = toVector(A,P), AB = toVector(A,B);
    double u = dotProduct(AP,AB)/norm_sq(AB); ///Projection of AP on AB
    if(_segment)
    {
        if(u<0.0) C=A;
        else if(u>1.0) C=B;
        else C = translate(A, scale(AB,u));
    }
    else C = translate(A, scale(AB,u)); ///C = A + u*AB
    return dist(C,P);
}

///Given a point P and a line L(mirror) and R is reflection of P
point mirrorPoint(point P, point A, point B)
{
    point C, R;
    distToLineOrSeg(P,A,B,C,false);
    R = translate(P, scale(toVector(P,C),2.0));
    return R;
}

///Angle AOB in rad
double angle(point A, point O, point B)
{
    vec OA = toVector(O,A), OB = toVector(O,B);
    return acos(dotProduct(OA,OB)/(sqrt(norm_sq(OA)*norm_sq(OB))));
}

///CCW angle from x axis to the vector in rad
double angleWRTx(vec v)
{
    double rad=atan2(v.y, v.x);
    if(rad<0.0) rad=2.0*pi+rad;
    return rad;
}

///Returns true if point R is on the same line as the line PQ
bool collinear(point P, point Q, point R)
{
    return fabs(crossProduct(toVector(P, Q), toVector(P, Q))) < eps;
}

///Returns true if point r is on the left side of line PQ
bool ccw(point P, point Q, point R)
{
    if(collinear(P,Q,R))
        return crossProduct(toVector(P, Q), toVector(P, R))>=0; ///for collinear point
    return crossProduct(toVector(P, Q), toVector(P, R))>0;
}

///Triangle

///Angle between edges A and B (length of the edges of triangles are A, B, C)
double angleFromLength(double A, double B, double C)
{
    return acos((A*A+B*B-C*C)/(2.0*A*B));
}

///Area of the triangle with edge lengths A, B, C
double areaFromLength(double A, double B, double C)
{
    double s=(A+B+C)/2.0;
    return sqrt(s*(s-A)*(s-B)*(s-C));
}

///Circle

///The radius of the circle surrounding the triangle
double rCircumCircle(double ab, double bc, double ca)
{
    return ab * bc * ca / (4.0 * areaFromLength(ab, bc, ca));
}
double rCircumCircle(point A, point B, point C)
{
    return rCircumCircle(dist(A, B), dist(B, C), dist(C, A));
}

///The radius of the circle surrounded by the triangle
double rInCircle(double ab, double bc, double ca)
{
    return areaFromLength(ab, bc, ca) / (0.5 * (ab+bc+ca));
}
double rInCircle(point A, point B, point C)
{
    return rInCircle(dist(A, B), dist(B, C), dist(C, A));
}

///Returns 1 if there is an inCircle(circle surrounded by the triangle) center
///If this function returns 1, ctr will be the inCircle center and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r)
{
    r=rInCircle(p1, p2, p3);
    if(fabs(r)<eps) return 0; /// no inCircle center
    double ration = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVector(p2, p3), ration / (1 + ration)));
    ration = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVector(p1, p3), ration / (1 + ration)));
    doIntersect(p1, p, p2, p, ctr); /// get their intersection point
    return 1;
}

///The overlapped area(union) of two circles
///First circle center c1 and radius r1
///Second circle center c2 and radius r2
double overlapCircleArea(point c1, double r1, point c2, double r2)
{
    double d, rad1, rad2, area1, area2, chord;
    if(r1>r2)
    {
        swap(c1, c2);
        swap(r1, r2);
    }
    d=dist(c1, c2);
    if(d>=r1+r2) return 0;
    if(d<=r2-r1) return pi*r1*r1;
    rad1=angleFromLength(r1, d, r2), rad2=angleFromLength(r2, d, r1);
    chord=2.0*r1*sin(rad1);
    area1=(r1*r1*rad1)-((2*rad1>pi)?-1:1)*areaFromLength(r1, r1, chord);
    area2=(r2*r2*rad2)-areaFromLength(r2, r2, chord);
    return area1+area2;
}

///Polygon

///Returns true if the point p is inside polygon(first point=last point)
bool inPolygon(point poly[], int n, point p)
{
    int i, j, k;
    double totAngle=0;
    for(i=0; i<n; ++i)
        if(poly[i].x==p.x && poly[i].y==p.y)
            return true;  ///if it overlaps with some point
    for(i=1; i<n; ++i)
        if(collinear(p, poly[i-1], poly[i]) && onSegment(p, poly[i-1], poly[i]))
            return true; ///if it is in some edges of the polygon
    for(i=1; i<n; ++i)
    {
        if(ccw(poly[i-1], p, poly[i])) totAngle-=angle(poly[i-1], p, poly[i]);
        else totAngle+=angle(poly[i-1], p, poly[i]);
    }
    return fabs(totAngle-2.0*pi)<eps;
}

///CONVEX HULL

double cross(point p1, point p2, point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
///Returns the Hull created by the n points of ara[]
///Does not take linear points in the hull
vector< point > ConvexHull(int n, point ara[])
{
    int i, j, k;
    vector< point > cnvx(2*n);
    sort(ara, ara+n);
    for(i=0, k=0; i<n; ++i)
    {
        while(k>=2 && cross(cnvx[k-2], cnvx[k-1], ara[i])<=0) k--;
        cnvx[k++]=ara[i];
    }
    for(i=n-2, j=k+1; i>=0; --i)
    {
        while(k>=j && cross(cnvx[k-2], cnvx[k-1], ara[i])<=0) k--;
        cnvx[k++]=ara[i];
    }
    cnvx.resize(k-1); ///Not taking the last point as first point
    return cnvx;
}

bool check(point A, point B, int n, point p[])
{
    vector<point>baki;
    for(int i = 0; i < n; i++)
    {
        if(cross(A,B,p[i])!=0)
            baki.push_back(p[i]);
    }
    bool flag = true;
    for(int i = 2; i < baki.size(); i++)
    {
        if(cross(baki[0],baki[1],baki[i])!=0)
            flag = false;
    }
    if(flag)
        return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    point p[n+5];
    for(int i = 0; i < n; i++)
        cin>>p[i].x>>p[i].y;

    if(n<=4) cout<<"YES"<<endl;
    else if(check(p[0],p[1], n, p)) cout<<"YES"<<endl;
    else if(check(p[0],p[2], n, p)) cout<<"YES"<<endl;
    else if(check(p[0],p[3], n, p)) cout<<"YES"<<endl;
    else if(check(p[1],p[2], n, p)) cout<<"YES"<<endl;
    else if(check(p[1],p[3], n, p)) cout<<"YES"<<endl;
    else if(check(p[2],p[3], n, p)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
