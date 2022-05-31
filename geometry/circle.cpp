#define ld long double
const ld PI = 3.141592653589793;
struct Point {
    ld x, y;
    Point() : x(0.0), y(0.0) {}
    Point(ld _x, ld _y) : x(_x), y(_y){};
};
struct Circle{
    ld centerx,centery,radius;
    Circle(){}
    Circle(ld _cx,ld _cy,ld _radius):centerx(_cx),centery(_cy),radius(_radius){}
    ld getArea()const{
        return PI*radius*radius;
    }
    ld getPerimeter()const{
        return PI*radius*2;
    }
};
/**
 * @brief function returning circle which passes through the three points p1,p2,p3
 * 
 * @param p1 point 1
 * @param p2 point 2
 * @param p3 point 3
 * @return Circle resulting circle
 */
Circle findCircle(Point &p1,Point&p2,Point&p3) {
    ld x1=p1.x,y1=p1.y,x2=p2.x,y2=p2.y,x3=p3.x,y3=p3.y;
    ld x12 = x1 - x2;
    ld x13 = x1 - x3;
    ld y12 = y1 - y2;
    ld y13 = y1 - y3;
    ld y31 = y3 - y1;
    ld y21 = y2 - y1;
    ld x31 = x3 - x1;
    ld x21 = x2 - x1;
    ld sx13 = powl(x1, 2) - powl(x3, 2);
    ld sy13 = powl(y1, 2) - powl(y3, 2);
    ld sx21 = powl(x2, 2) - powl(x1, 2);
    ld sy21 = powl(y2, 2) - powl(y1, 2);
    ld f = ((sx13) * (x12) + (sy13) * (x12) + (sx21) * (x13) + (sy21) * (x13)) / (2 * ((y31) * (x12) - (y21) * (x13)));
    ld g = ((sx13) * (y12) + (sy13) * (y12) + (sx21) * (y13) + (sy21) * (y13)) / (2 * ((x31) * (y12) - (x21) * (y13)));
    ld c = -powl(x1, 2) - powl(y1, 2) - 2 * g * x1 - 2 * f * y1;
    ld h = -g;
    ld k = -f;
    ld sqr_of_r = h * h + k * k - c;
    ld r = sqrt(sqr_of_r);
    return Circle(h,k,r);
}