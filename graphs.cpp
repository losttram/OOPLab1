using namespace std;

#include <iomanip>
#include <iostream>
#include "graphs.h"

// evenGraph writes histogram of evenly distributed pseudorandom numbers.
void evenGraph(int *a, int total) {
    int tCopy = total;
    int tLen;

    cout << "Interval\tFrequency" << endl;

    for (tLen = 0; tCopy > 9; tLen++) {
        tCopy /= 10;
    }

    for (int i = 0; i < 10; i++) {
        int n = *a;

        cout << fixed << setprecision(1);

        cout << "[" << (float) i / 10 << "; " << (float) (i + 1) / 10 << "]" << "\t";

        cout << fixed << setprecision(tLen);

        cout << (float) n / (float) total << endl;

        a++;
    }
}

// normalGraph writes histogram of normally distributed pseudorandom numbers.
void normalGraph(int *a, int total) {
    int tCopy = total;
    int tLen;
    float interval = -3;

    cout << "Interval\tFrequency" << endl;

    for (tLen = 0; tCopy > 9; tLen++) {
        tCopy /= 10;
    }

    for (int i = 0; i < 10; i++) {
        int n = *a;

        cout << fixed << setprecision(1);

        cout << "[" << interval + 0.6 * i << "; " << interval + 0.6 * (i + 1) << "]" << "\t";

        cout << fixed << setprecision(tLen);

        cout << (float) n / (float) total << endl;

        a++;
    }
}

// otherGraph writes histogram of evenly distributed pseudorandom numbers.
void otherGraph(int *a, int total) {
    int tCopy = total;
    int tLen;

    cout << "Interval\tFrequency" << endl;

    for (tLen = 0; tCopy > 9; tLen++) {
        tCopy /= 10;
    }

    cout << fixed << setprecision(tLen);

    for (int i = 0; i < 10; i++) {
        int n = *a;

        cout << "[" << i * 10 << "; " << (i + 1) * 10 << "]\t";

        if (i == 0) {
            cout << "\t";
        }

        cout << (float) n / (float) total << endl;

        a++;
    }
}