using namespace std;

#include <iostream>
#include "communicator.h"
#include "generators.h"
#include "graphs.h"

// Chatter communicates with the user.
void Chatter() {
    int gNum;

    cout << "Enter which generator you want to use (1 - 10) - >";
    cin >> gNum;
    Router(gNum);
}

// Router calls generator of user's choice.
void Router(int gNum) {
    int iterations = 10000;
    int stat[10] = {0};

    switch (gNum) {
        case 1:
            Linear(stat, iterations);
            evenGraph(stat, iterations);

            break;

        case 2:
            Squared(stat, iterations);
            evenGraph(stat, iterations);

            break;

        case 3:
            Fibonacci(stat, iterations);
            evenGraph(stat, iterations);

            break;

        case 4:
            Reversed(stat, iterations);
            evenGraph(stat, iterations);

            break;

        case 5:
            Combinated(stat, iterations);
            evenGraph(stat, iterations);

            break;

        case 6:
            Sigma(stat, iterations);
            normalGraph(stat, iterations);

            break;

        case 7:
            Polar(stat, iterations);
            normalGraph(stat, iterations * 2);

            break;

        case 8:
            Correlations(stat, iterations);
            normalGraph(stat, iterations);

            break;

        case 9:
            Log(stat, iterations);
            otherGraph(stat, iterations);

            break;

        case 10:
            Arens(stat, iterations);
            otherGraph(stat, iterations);

            break;

        default:
            cout << "You wrote unsupported number." << endl;
            break;
    }
}