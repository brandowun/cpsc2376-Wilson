#include <iostream>

struct Point {
    float x;
    float y;
};

Point calcMidpoint(const Point* p1, const Point* p2) {
    Point middlePoint;
    middlePoint.x = (p1->x + p2->x) / 2;
    middlePoint.y = (p1->y + p2->y) / 2;
    return middlePoint;
}

int main() {
    Point a;
    a.x = 1.0f;
    a.y = 2.0f;

    Point b;
    b.x = 5.0f;
    b.y = 6.0f;

    Point mid = calcMidpoint(&a, &b);

    std::cout << "Midpoint is at (" << mid.x << ", " << mid.y << ")" << std::endl;

    return 0;
}
