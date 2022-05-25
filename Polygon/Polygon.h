//
// Created by Всеволод on 19.04.2022.
//

#ifndef POLYGON_POLYGON_H
#define POLYGON_POLYGON_H

#include <iostream>
#include <vector>
#include <cmath>

#define _USE_MATH_DEFINES


using namespace std;

template<typename T, int N>
class Polygon {
private:
    int size = N;
    vector<pair<T, T>> arr = vector<pair<T, T>>(N);
public:
    Polygon(vector<pair<T, T>> coord);
    void addNode(int pos, pair<T, T> node);
    double getPerimeter();
    void print() const;
};

template<typename T, int N>
Polygon<T, N>::Polygon(vector<pair<T, T>> coord) {
    for (int i = 0; i < N; i++) {
        arr[i].first = coord[i].first;
        arr[i].second = coord[i].second;
    }
}

template<typename T, int N>
void Polygon<T, N>::addNode(int pos, pair<T, T> node) {
    size++;
    if (size > N) arr.resize(size);
    arr.insert(arr.begin() + pos, node);
}

template<typename T, int N>
double Polygon<T, N>::getPerimeter() {
    double per = 0;
    for (int i = 0; i < size; i++) {
        int j = ((i - 1) % size + size) % size;
        T deltaX = arr[i].first - arr[j].first;
        T deltaY = arr[i].second - arr[j].second;
        per += sqrt(deltaX * deltaX + deltaY * deltaY);
    }
    return per;
}

template<typename T, int N>
void Polygon<T, N>::print() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i].first << ' ' << arr[i].second << endl;
    }
}

//################

template<int N>
class Polygon<double, N> {
private:
    int size = N;
    vector<pair<double, double>> arr = vector<pair<double, double>>(N);
public:
    Polygon(vector<pair<double, double>> coord);
    void addNode(int pos, pair<double, double> node);
    double getPerimeter();
    void print() const;
    void turnOn(int angle);
};

template<int N>
Polygon<double, N>::Polygon(vector<pair<double, double>> coord) {
    for (int i = 0; i < N; i++) {
        arr[i].first = coord[i].first;
        arr[i].second = coord[i].second;
    }
}

template<int N>
void Polygon<double, N>::addNode(int pos, pair<double, double> node) {
    size++;
    if (size > N) arr.resize(size);
    arr.insert(arr.begin() + pos, node);
}

template<int N>
double Polygon<double, N>::getPerimeter() {
    double per = 0;
    for (int i = 0; i < size; i++) {
        int j = ((i - 1) % size + size) % size;
        double deltaX = arr[i].first - arr[j].first;
        double deltaY = arr[i].second - arr[j].second;
        per += sqrt(deltaX * deltaX + deltaY * deltaY);
    }
    return per;
}

template<int N>
void Polygon<double, N>::print() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i].first << ' ' << arr[i].second << endl;
    }
}

template<int N>
void Polygon<double, N>::turnOn(int angle) {
    double x0 = arr[0].first, y0 = arr[0].second;
    for (int i = 1; i < size; i++) {
        double x = arr[i].first, y = arr[i].second;
        arr[i].first = x0 + cos((angle * M_PI) / 180) * x - sin((angle * M_PI) / 180) * y;
        arr[i].second = y0 + sin((angle * M_PI) / 180) * x + cos((angle * M_PI) / 180) * y;
    }
}



#endif //POLYGON_POLYGON_H
