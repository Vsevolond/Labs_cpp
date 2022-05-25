//
// Created by Всеволод on 23.04.2022.
//

#ifndef CURVE_CURVE_H
#define CURVE_CURVE_H


#include <iostream>
#include <cmath>
#include <optional>

using namespace std;

template <typename T = double>
class Curve {
private:
    T x, y;
public:
    Curve() = default;
    Curve(optional<T> arg, optional<T> val) {
        if (arg && val) {
            x = *arg;
            y = *val;
        }
        else if (arg) {
            x = *arg;
            y = exp(x);
        } else if (val) {
            y = *val;
            x = log(y);
        }
    }

    void print();
    T val();
    T arg();

    Curve<T> &operator=(Curve<T> func);
    Curve<T> operator+(Curve<T> func);
    Curve<T> operator-(Curve<T> func);
    Curve<T> operator*(double k);
    Curve<T> operator-();
    Curve<T> operator!();
    T operator()(T arg);
};

template<typename T>
T Curve<T>::val() {
    return y;
}

template<typename T>
T Curve<T>::arg() {
    return x;
}

template<typename T>
void Curve<T>::print() {
    cout << "f(" << x << ") = " << y << endl;
}

template<typename T>
Curve<T> Curve<T>::operator+(Curve<T> func) {
    return Curve<T>(nullopt, y + func.val());
}

template<typename T>
Curve<T> operator+(const Curve<T>& a, const Curve<T>& b) {
    return Curve<T>(nullopt, a.val() + b.val());
}

template<typename T>
Curve<T> operator-(const Curve<T>& a, const Curve<T>& b) {
    return Curve<T>(nullopt, a.val() - b.val());
}

template<typename T>
Curve<T> Curve<T>::operator-(Curve<T> func) {
    return Curve<T>(nullopt, y - func.val());
}

template<typename T>
Curve<T> &Curve<T>::operator=(Curve<T> func) {
    x = func.x;
    y = func.y;
    return *this;
}

template<typename T>
Curve<T> Curve<T>::operator*(double k) {
    return Curve<T>(nullopt, k * y);
}

template<typename T>
Curve<T> Curve<T>::operator-() {
    return Curve<T>(x, -y);
}

template<typename T>
Curve<T> Curve<T>::operator!() {
    return Curve<T>(x, y);
}

template<typename T>
T Curve<T>::operator()(T arg) {
    return exp(arg);
}



#endif //CURVE_CURVE_H
