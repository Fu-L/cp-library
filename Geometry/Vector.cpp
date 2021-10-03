// ベクトル(点)を扱う。
const long double pi=acos(-1);
const long double eps=1e-7;
struct V{
    long double x,y;
    V(long double x=0,long double y=0):x(x),y(y){}
    V& operator+=(const V& v){x+=v.x; y+=v.y; return *this;}
    V operator+(const V& v)const{return V(*this)+=v;}
    V& operator-=(const V& v){x-=v.x; y-=v.y; return *this;}
    V operator-(const V& v)const{return V(*this)-=v;}
    V& operator*=(long double s){x*=s; y*=s; return *this;}
    V operator*(long double s)const{return V(*this)*=s;}
    V& operator/=(long double s){x/=s; y/=s; return *this;}
    V operator/(long double s)const{return V(*this)/=s;}
    long double dod(const V& v)const{return x*v.x+y*v.y;}
    long double cross(const V& v)const{return x*v.y-y*v.x;}
    long double abs(V v)const{return sqrt(v.x*v.x+v.y*v.y);}
    long double dist(V v1,V v2)const{return abs(v2-v1);}
    long double arg(const V& v)const{return atan2(v.y,v.x);}
    V rotate(long double theta){return V(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));}
    bool operator<(const V& v)const{
        long double theta=arg(V(x,y));
        long double vtheta=arg(v);
        return theta<vtheta;
    }
};
