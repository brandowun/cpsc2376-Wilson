#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <memory>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual string shapeName() const = 0;
};
//rectangle class
class rectangle : public Shape {
    double width, height;
public:
    rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;

    }
    string shapeName() const override {
        return "Rectangle ";
    }

};
//circle class
class circle : public Shape {
    double radius;
public:
    circle(double r) : radius(r) {}
    double area() const override {
        //for P.I
        return M_PI * radius * radius;
    }
    string shapeName() const override {
        return "circle ";
    }
};


//printing out from file
void printArea(const vector<unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        cout << shape->shapeName() << "area: " << fixed << setprecision(4) << shape->area() << endl;
    }
}


int main() {
    ifstream input("shapes.txt");
    if (!input) {
        cerr << "Somethings wrong" << endl;
        return 1;
    }

    vector<unique_ptr<Shape>> shapes;
    string fileLine;
    
    while (getline(input, fileLine)) {

        stringstream shapeParser(fileLine);
        string shapeType;
        shapeParser >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            shapeParser >> width >> height;
            shapes.push_back(make_unique<rectangle>(width, height));

        } else if (shapeType == "circle") {
            double radius;
            shapeParser >> radius;
            shapes.push_back(make_unique<circle>(radius));
        }
    }
    printArea(shapes);
    return 0;
}
