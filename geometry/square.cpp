#define ld long double
/**
 * @brief this is what you think it is
 * 
 */
struct Point {
    ld x, y;
    Point() : x(0.0), y(0.0) {}
    Point(ld _x, ld _y) : x(_x), y(_y){};
};
/**
 * @brief Get the area of Triangle fomed by a,b and c
 * @param a 
 * @param b 
 * @param c 
 * @return area of triangle formed by points a,b and c 
 */
ld getTriangleArea(Point &a, Point &b, Point &c) {
    ld area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return abs(area) / 2.0;
}

/**
 * @brief returns all four coordinates of the square
 * while opposite corners are given
 * @param x1 
 * @param y1 
 * @param x3 
 * @param y3 
 * @return vector<Point> square object 
 */
vector<Point> getSquare(ld x1, ld y1, ld x3, ld y3) {
    vector<Point> points;
    points.emplace_back(Point(x1, y1));
    points.emplace_back(Point((x1 + x3 + y1 - y3) / 2.0, (x3 - x1 + y1 + y3) / 2.0));
    points.emplace_back(Point(x3, y3));
    points.emplace_back(Point((x1 + x3 + y3 - y1) / 2.0, (x1 - x3 + y1 + y3) / 2.0));
    return points;
}
/**
 * @brief Get the Area of square
 * 
 * @param square 
 * @return area of square object 
 */
ld getSquareArea(vector<Point> &square) {
    return dist2(square[0], square[1]);
}
/**
 * @brief checks if a point lies inside a square which is not neccessarily
 * parrallel to corordinate axis
 * @param square a square
 * @param p a point
 * @return true if point p lies inside square (even if lies on side)
 * @return false if point p does not lies inside square
 */
bool isInsideSquare(vector<Point> &square, Point &p) {
    ld totalArea = 0;
    FOR(i, 0, 4) {
        totalArea += getTriangleArea(square[i], square[(i + 1) % 4], p);
    }
    return fabs(totalArea - getSquareArea(square)) < EPS;
}