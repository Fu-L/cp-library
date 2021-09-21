// 点を扱う。
const long double pi=acos(-1);
const long double eps=1e-7;
struct Point{
    long double x,y;
    Point() {}
    Point(long double x,long double y):x(x),y(x){}
    Point operator+(Point p){return Point(x+p.x,y+p.y);}
    Point operator-(Point p){return Point(x-p.x,y-p.y);}
    Point operator*(long double d){return Point(x*d,y*d);}
    Point operator/(long double d){return Point(x/d,y/d);}
    long double dod(Point p){return x*p.x+y*p.y;}
    long double cross(Point p){return x*p.y-y*p.x;}
    long double abs(Point p){return sqrt(p.x*p.x+p.y*p.y);}
    long double dist(Point p,Point q){return abs(q-p);}
    long double arg(Point p){return atan2(p.y,p.x);}
    Point rotate(long double theta){return Point(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));}
};
