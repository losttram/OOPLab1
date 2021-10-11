using namespace std;

#include <iostream>
#include <cmath>
#include "generators.h"
#include "check.h"

// Linear is first generator method.
float Linear(int *stat, int iterations) {
    int a = 13;
    int c = 35;
    int m = 1728;
    int x;
    float u = 0;

    if (!coPrime(c, m)) {
        cout << "Numbers c and m are not co-prime." << endl;
        cout << "Use other values!" << endl;

        return u;
    }

    if (!commonDividers(a - 1, m)) {
        cout << "Number a-1 is not dividable by every prime divider of m." << endl;
        cout << "Use other values!" << endl;

        return u;
    }

    if (m % 4 == 0 && (a - 1) % 4 != 0) {
        cout << "m is dividable by 4 whereas a-1 is not." << endl;
        cout << "Use other values!" << endl;

        return u;
    }

    for (int i = 1; i <= iterations; i++) {
        x = (a * x + c) % m;
        u = (float) x / (float) m;

        for (int j = 1; j <= 10; j++) {
            if (u <= (float) j / 10) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return u;
}

// Squared is second generator method.
float Squared(int *stat, int iterations) {
    int a = 13;
    int c = 35;
    int d = 12;
    int m = 1728;
    int x;
    float u = 0;

    if (!coPrime(c, m)) {
        cout << "Numbers c and m are not co-prime." << endl;
        cout << "Use other values!" << endl;

        return u;
    }

    if (!commonOddDividers(d, m)) {
        cout << "Number d is not dividable by every odd prime divider of m." << endl;
        cout << "Use other values!" << endl;

        return u;
    }

    if (!commonOddDividers(a - 1, m)) {
        cout << "Number a-1 is not dividable by every odd prime divider of m." << endl;
        cout << "Use other values!" << endl;

        return u;
    }

    if (m % 4 == 0) {
        if (d % 2 != 0 || d % 4 != (a - 1) % 4) {
            cout << "m is dividable by 4 whereas (d mod 4) and ((a-1) mod 4) are not equal." << endl;
            cout << "Use other values!" << endl;

            return u;
        }
    }

    if (m % 3 == 0) {
        if (d % 9 == (3 * c) % 9) {
            cout << "m is dividable by 3 but (d mod 9) and ((3*c) mod 9) are equal." << endl;
            cout << "Use other values!" << endl;

            return u;
        }
    }

    for (int i = 1; i <= iterations; i++) {
        x = (d * x * x + a * x + c) % m;
        u = (float) x / (float) m;

        for (int j = 1; j <= 10; j++) {
            if (u <= (float) j / 10) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return u;
}

// Fibonacci is third generator method.
float Fibonacci(int *stat, int iterations) {
    int m = 1170; // Supposed birth year of Fibonacci.
    int x1 = 1;
    int x2 = 2;
    float u = 0;

    for (int i = 1; i <= iterations; i++) {
        x1 = (x1 + x2) % m;
        x2 += x1;
        x1 = x2 - x1;
        x2 -= x1;

        u = (float) x2 / (float) m;

        for (int j = 1; j <= 10; j++) {
            if (u <= (float) j / 10) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return u;
}

// Reversed is fourth generator method.
float Reversed(int *stat, int iterations) {
    int p = 3457;
    int a = 401;
    int c = 3602;
    int x = 1;
    float u = 0;

    if (!isPrime(p)) {
        if (a % 4 == 1 & c % 4 == 2 && log2(p) >= 3) {
            if ((float) (int) log2(p) != log2(p)) {
                cout << "P is not a prime number, a mod 4 is 1 and c mod 4 is 2, but e is not an integer." << endl;
                cout << "Use other values!" << endl;

                return u;
            }
        }
    }

    for (int i = 1; i <= iterations; i++) {
        if (x == 0) { x++; }

        while (x >= p) {
            x--;
        }

        int xRev = rev(x, p);

        x = (a * xRev + c) % p;

        u = (float) x / (float) p;

        for (int j = 1; j <= 10; j++) {
            if (u <= (float) j / 10) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return u;
}

// Combinated is fifth generator method.
float Combinated(int *stat, int iterations) {
    int m = 2550;
    int x;
    int y;
    int z;
    int key = 123;
    float u;

    for (int i = 1; i <= iterations; i++) {
        int arr[10] = {0};
        x = -1;
        y = -1;

        for (int j = 0; x < 0 || x > m || y < 0; j++) {
            key++;
            x = (int) (Linear(arr, key) * (float) m);
            y = (int) (Squared(arr, key) * (float) m);
        }

        z = (((x - y) % m) + m) % m;
        u = (float) z / (float) m;

        for (int j = 1; j <= 10; j++) {
            if (u <= (float) j / 10) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return u;
}

// Sigma is sixth generator method.
float Sigma(int *stat, int iterations) {
    float x;
    float m = 0;
    float sigma = 1;
    int key = 15;

    for (int i = 1; i <= iterations; i++) {
        int arr[10] = {0};
        float sum = 0;

        for (int j = 0; j < 10; j += 3) {
            key++;

            sum += Linear(arr, key);
            sum += Squared(arr, key);
            sum += Fibonacci(arr, key);
        }

        x = m + (sum - 6) * sigma;

        for (int j = 1; j <= 10; j++) {
            auto interval = (float) (-3 + j * 0.6);

            if (x <= interval) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return x;
}

// Polar is seventh generator method.
float Polar(int *stat, int iterations) {
    float x1, x2;
    int key = 0;

    for (int i = 1; i <= iterations; i++) {
        float v1, v2;
        float s = 1;
        int arr[10] = {0};

        for (int j = 0; s >= 1 || x1 < -3 || x1 > 3 || x2 < -3 || x2 > 3; j++) {
            key++;
            float u1 = Linear(arr, key);
            float u2 = Squared(arr, key);

            v1 = 2 * u1 - 1;
            v2 = 2 * u2 - 1;

            s = v1 * v1 + v2 * v2;

            x1 = v1 * sqrt((-2 * log(s)) / s);
            x2 = v2 * sqrt((-2 * log(s)) / s);

        }

        for (int j = 1; j <= 10; j++) {
            auto interval = (float) (-3 + j * 0.6);

            if (x1 <= interval) {
                stat[j - 1]++;

                break;
            }
        }

        for (int j = 1; j <= 10; j++) {
            auto interval = (float) (-3 + j * 0.6);

            if (x2 <= interval) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return x2;
}

// Correlations is eighth generator method.
float Correlations(int *stat, int iterations) {
    float x;
    int key = 0;

    for (int i = 1; i <= iterations; i++) {
        float u = 0;
        float v;
        int arr[10] = {0};

        for (int j = 0; u == 0 || x < -3 || x > 3; j++) {
            key++;
            u = Linear(arr, key);
            v = Squared(arr, key);

            x = (float) (sqrt(8 / exp(1)) * ((v - 0.5) / u));
        }

        for (int j = 1; j <= 10; j++) {
            auto interval = (float) (-3 + j * 0.6);

            if (x <= interval) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return x;
}

// Log is ninth generator method.
float Log(int *stat, int iterations) {
    float x;
    float u;
    float mu = 13;
    int key = 351;

    for (int i = 1; i <= iterations; i++) {
        key++;

        int arr[10] = {0};

        u = Squared(arr, key);

        x = (-mu) * log(1 - u);

        for (int j = 1; j <= 10; j++) {
            if (x <= (float) j * 10) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return x;
}

// Arens is tenth generator method.
float Arens(int *stat, int iterations) {
    float a = 4;
    float u, v;
    float x, y;
    int key = 378;

    for (int i = 1; i <= iterations; i++) {
        int arr[10] = {0};
        x = 0;

        for (int j = 0; x <= 0; j++) {
            key++;

            u = Squared(arr, key);
            y = (float) tan(M_PI * u);
            x = (float) sqrt(2 * a - 1) * y + a - 1;

            v = Squared(arr, key + 1);
            if (v > (1 + pow(y, 2)) * exp((a - 1) * log(x / (a - 1)) - sqrt(2 * a - 1) * y)) {
                continue;
            }
        }

        for (int j = 1; j <= 10; j++) {
            if (x <= (float) j * 10) {
                stat[j - 1]++;

                break;
            }
        }
    }

    return x;
}