//
// Created by Всеволод on 24.04.2022.
//

#ifndef SEGMENTS_SEGMENTS_H
#define SEGMENTS_SEGMENTS_H


#include <iostream>

using namespace std;

class Segments {
private:
    int* arr;
    int size;
public:
    class Iterator;
    Segments(int* a, int n) : arr(a), size(n){}

    int& operator[](const int& i) { return arr[i]; }

    Iterator begin() { return arr + 1; }
    Iterator end() { return arr + size - 1; }

    class Iterator {
        int* cur;
    public:
        Iterator(int* first) : cur(first) {}

        int&  operator++ (int) { return *cur++; }
        int&  operator++ () { return *++cur; }

        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator== (const Iterator& it) { return cur == it.cur; }

        Iterator operator+=(int x) {
            cur += x;
            return *this;
        }

        int& operator* () {
            int left = *(cur - 1), num = *cur, right = *(cur + 1);
            int res = left + num + right;
            return res;
        }
    };
};


#endif //SEGMENTS_SEGMENTS_H
