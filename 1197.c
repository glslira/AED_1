#include <stdio.h>

int main() {
    int v, t;

    while (scanf("%d %d", &v, &t) != EOF) {
        printf("%d\n", v * 2 * t);
    } //while

    return 0;
} //main
