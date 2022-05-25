#include "Segments.h"

int main() {
    int ex[] {1, 2, 3, 4, 5, 6};
    Segments x(ex, 6);

    auto it = Segments::Iterator(x.begin());
    while (it != x.end()) {
        cout << *it << ' ';
        it++;
    }
    cout << endl;
    for(int i = 0; i < 6; i++)
        cout << x[i] << ' ';
    return 0;
}
