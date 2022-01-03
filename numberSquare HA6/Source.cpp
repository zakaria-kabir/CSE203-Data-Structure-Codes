#include <iostream>
using namespace std;
void numberSquare(int min, int max) {
    int numInSequence = max - min + 1;
    for (int j = min; j <= max; j++) {
        int i = j;
        while (numInSequence != 0) {
            cout << i;
            i++;
            if (i > max) {
                i = min;
            }
            numInSequence--;
        }
        numInSequence = max - min + 1;
        cout << endl;
    }
}

int main() {
    numberSquare(1, 5);
    return 0;
}
