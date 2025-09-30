#include <iostream>
using namespace std;

// Naive GCD function
int naiveGCD(int a, int b) {
    int best = 0;
    for (int d = 1; d <= a + b; d++) {
        if (a % d == 0 && b % d == 0) {
            best = d;
        }
    }
    return best;
}

// Euclidean GCD function
int euclidGCD(int a, int b) {
    if (b == 0)
        return a;
    return euclidGCD(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int gcdNaive = naiveGCD(a, b);
    int gcdEuclid = euclidGCD(a, b);

    cout << "Naive GCD of " << a << " and " << b << " = " << gcdNaive << endl;
    cout << "Euclidean GCD of " << a << " and " << b << " = " << gcdEuclid << endl;

    return 0;
}
