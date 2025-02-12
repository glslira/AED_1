#include <stdio.h>
#include <stdlib.h>

long long int F[21];

long long int Fatorial(int n) {
    if (F[n] == 0) {
        F[n] = n * Fatorial(n - 1);
    } //if
    return F[n];
} //Fatorial

int main() {
    int M, N;

    for (int i = 0; i < 21; i++) {
        F[i] = 0;
    } //for
    F[0] = 1;

    while (scanf("%d %d", &M, &N) != EOF) {
        printf("%lld\n", Fatorial(M) + Fatorial(N));
    } //while

    return 0;
} //main
