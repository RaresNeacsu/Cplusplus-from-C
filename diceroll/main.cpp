#include <iostream>
#include <ctime>
#include <cstdlib>
const int sides = 6;
const int dice = 2;
inline int roll() { return rand() % sides + 1; }
using namespace std;
int main() {
    srand(clock());
    cout << "Number of trials: ";
    long int trials;
    int d1,d2;
    int *outcomes = new int[sides * dice +1];
    cin >> trials;
    for (long int i = 0; i < trials; i++) {
        d1 = roll();
        d2 = roll();
        outcomes[d1 + d2]++;
    }
    double s = 0;
    for (int i = 2; i <= sides * dice; i++) {
        cout << "Probability of " << i << ": " << 100.0 * static_cast<double>(outcomes[i]) / trials << "\n";
        s += 100.0 * static_cast<double>(outcomes[i]) / trials;
    }
    cout << "Sum: " << s << "\n";
    delete[] outcomes;
    return 0;
}