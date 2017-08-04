///uva 10112
#include <iostream>
#include <cmath>
using namespace std;

#define Pi 3.141592653568979323846
#define eps 1e-8
#define sgn(d) (((d)<-eps)?(-1):(((d)>+eps)?(+1):(0)))
#define Sqr(x) ((x)*(x))
#define Sqrt(x) (sqrt((x)))
#define Abs(x) ((x)<0?(-(x)):(x))
#define Deg2Red(deg) ((deg)*Pi/180.0)
#define Red2Deg(red) ((red)*180.0/Pi)
#define Sin(deg) (sin(Deg2Red((deg))))
#define Cos(deg) (cos(Deg2Red((deg))))
#define ArcSin(val) (Red2Deg(asin((val))))
#define ArcCos(val) (Red2Deg(acos((val))))
#define fcmp(a,b) (sgn((a)-(b)))
struct Point{
    double x,y;
    char NumberName;
    Point(){
        x=0;
        y=0;
        NumberName='\0';
    }
    Point(double _x,double _y){
        x=_x;
        y=_y;
        NumberName='\0';
    }
};

struct Vect{
    double x,y;
    Vect(){
        x=0;
        y=0;
    }
    Vect(double _x,double _y){
        x=_x;
        y=_y;
    }
    Vect(Point& a,Point& b){
        x=b.x-a.x;
        y=b.y-a.y;
    }
    double length(){
        return Sqrt(Sqr(x)+Sqr(y));
    }
};

struct Maxinum{
    int i,j,k;
    double square;
    Maxinum(){i=0;j=0;k=0;square=0;}
};

double operator^(const Vect& a,const Vect& b){
    return a.x*b.y-a.y*b.x;
}

double operator*(const Vect& a,const Vect& b){
    return a.x*b.x+a.y*b.y;
}

double angle(Vect& a,Vect& b){
    return ArcSin((a^b)/(a.length()*b.length()));
}

ostream&operator<<(ostream&os,const Vect& v){
    os<<"("<<v.x<<","<<v.y<<")";
    return os;
}
int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        Point DataSet[15];
        Maxinum Max;
        for(int i=0;i<n;i++){
            cin>>DataSet[i].NumberName>>DataSet[i].x>>DataSet[i].y;
        }
        int i=0,j=1,k=2,IteratorOfPoint=0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(i>=j)continue;
                for(k=j+1;k<n;k++){
                    Vect v1(DataSet[i],DataSet[j]),v2(DataSet[i],DataSet[k]);
                    bool flag=0;
                    double s=Abs(v1^v2);
                    for(IteratorOfPoint=0;IteratorOfPoint<n;IteratorOfPoint++){
                        if(IteratorOfPoint==i||IteratorOfPoint==j||IteratorOfPoint==k)continue;
                        flag=1;
                        Vect v1(DataSet[IteratorOfPoint],DataSet[i]);
                        Vect v2(DataSet[IteratorOfPoint],DataSet[j]);
                        Vect v3(DataSet[IteratorOfPoint],DataSet[k]);
                        double s1,s2,s3;
                        s1=Abs(v1^v2);s2=Abs(v2^v3);s3=Abs(v3^v1);
                        double SquareReport=s1+s2+s3;
                        if(fcmp(SquareReport,s)==0){flag=0;break;}
                        else continue;
                    }
                    if(flag){
                        if(Max.square<s){
                            Max.square=s;
                            Max.i=i;
                            Max.j=j;
                            Max.k=k;
                        }
                        continue;
                    }
                    else continue;
                }
            }
        }
        cout<<DataSet[Max.i].NumberName;
        cout<<DataSet[Max.j].NumberName;
        cout<<DataSet[Max.k].NumberName;
        cout<<endl;
    }
    return 0;
}
