#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FACES 6
#define ROLL(FACES) (rand() % FACES + 1)
#define n_dice 2
#define n_outcomes FACES * n_dice

int main() {
    srand(clock());
    printf("Number of trials: ");
    int trials;
    int outcomes[n_outcomes] = {0};
    scanf("%d", &trials);
    for (int i = 0; i < trials; i++) {
        outcomes[ROLL(FACES) + ROLL(FACES)]++;
    }
    double s=0;
    for (int i = 2; i <= n_outcomes; i++) {
        printf("Probability of %d: %f\n", i, 100.0 * (double)outcomes[i] / trials);
        s+=100.0 * (double)outcomes[i] / trials;
    }
    printf("Sum: %f\n", s);
    return 0;
}
