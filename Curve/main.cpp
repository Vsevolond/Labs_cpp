#include "Curve.h"

int main() {
    Curve<double> x(2.0, nullopt);
    Curve<double> y(5.0, nullopt);

    Curve<double> res = x;
    res.print();

    res = x + y;
    res.print();

    res = y - x;
    res.print();

    res = x * 3;
    res.print();

    res = -x;
    res.print();

    res = !x;
    res.print();

    cout << x(5)<< endl;

    return 0;
}
