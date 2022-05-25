#include "Polygon.h"

int main() {
    vector<pair<double, double>> coord = {{1.5, 0.4}, {4.6, 5.8}, {9.2, 1.0}};
    Polygon<double, 3> polygon = Polygon<double, 3>(coord);

    cout << polygon.getPerimeter() << endl;
    cout << endl;

    polygon.addNode(2, {13.3, 4.9});
    polygon.print();
    cout << endl;

    polygon.turnOn(90);
    polygon.print();

    return 0;
}
