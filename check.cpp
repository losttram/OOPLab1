#include "check.h"

// coPrime checks if two integers are co-prime.
bool coPrime(int a, int b) {
    bool result = true;

    for (int i = 2; i <= a; i++) {
        if (a % i == 0 && b % i == 0) {
            result = false;
            break;
        }
    }

    return result;
}

// commonDividers checks if a divides by every prime divider of b.
bool commonDividers(int a, int b) {
    bool result = true;

    for (int i = 2; i <= a; i++) {
        if (!isPrime(i)) {
            continue;
        }

        if (a % i != 0 && b % i == 0) {
            result = false;
            break;
        }
    }

    return result;
}

// commonOddDividers checks if a divides by every odd prime divider of b.
bool commonOddDividers(int a, int b) {
    bool result = true;

    for (int i = 2; i <= a; i++) {
        if (!isPrime(i) || i % 2 == 0) {
            continue;
        }

        if (a % i != 0 && b % i == 0) {
            result = false;
            break;
        }
    }

    return result;
}

// isPrime checks if integer is a prime number.
bool isPrime(int a) {
    int h = a / 2;
    bool prime = true;

    for (int i = 2; i <= h; i++) {
        if ((a % i) == 0) {
            prime = false;
            break;
        }
    }

    return prime;
}

// rev reverses x.
int rev(int x, int p) {
    int res = 1;

    for (int d = p - 2; d; d /= 2) {
        if (d % 2) {
            res = (res * x) % p;
        }

        x = (x * x) % p;
    }
    return res;
}