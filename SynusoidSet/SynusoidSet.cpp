//
// Created by Всеволод on 02.04.2022.
//

#include "SynusoidSet.h"


SynusoidSet::SynusoidSet() {
    count = 0;
    synusoids = new Synusoid[count];
}

SynusoidSet::~SynusoidSet() {
    delete[] synusoids;
}

int SynusoidSet::getCount() const {
    return count;
}

SynusoidSet::Synusoid &SynusoidSet::operator[](int i) {
    return synusoids[i];
}

void SynusoidSet::pushSynusoid(double a, double d, double w) {
    Synusoid s = Synusoid(a, d, w);
    Synusoid dest[++count];
    for (int i = 0; i < count - 1; i++) {
        dest[i] = synusoids[i];
    }
    dest[count - 1] = s;
    delete[] synusoids;
    synusoids = new Synusoid[count];
    memcpy(synusoids, dest, count * sizeof(Synusoid));
}

double SynusoidSet::getValueFunc(int x) {
    double res = 0;
    for (int i = 0; i < count; i++) {
        res += synusoids[i].getValue(x);
    }
    return res;
}

void SynusoidSet::eraseSynusoid(int num) {
    Synusoid dest[--count];
    for (int i = 0; i < num; i++) {
        dest[i] = synusoids[i];
    }
    for (int i = num + 1; i < count + 1; i++) {
        dest[i - 1] = synusoids[i];
    }
    delete[] synusoids;
    synusoids = new Synusoid[count];
    memcpy(synusoids, dest, count * sizeof(Synusoid));
}

bool SynusoidSet::eraseSynusoidZeroPair(int x) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (synusoids[i].getValue(x) + synusoids[j].getValue(x) == 0) {
                eraseSynusoid(j);
                eraseSynusoid(i);
                return false;
            }
        }
    }
    return true;
}

void SynusoidSet::eraseSynusoidZeroPairs(int x) {
    bool flag = eraseSynusoidZeroPair(x);
    while (!flag) {
        flag = eraseSynusoidZeroPair(x);
    }
}

ostream &operator<<(ostream &out, SynusoidSet &s)
{
    for (int i = 0; i < s.count; i++) {
        out << s[i].getA() << ' ' << s[i].getD() << ' ' << s[i].getW() << endl;
    }
    return out;
}



