#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c;
    int min, mid, max;

    scanf("%d %d %d", &a, &b, &c);

    if (a <= b && a <= c) {
        min = a;
    } else if (b <= a && b <= c) {
        min = b;
    } else {
        min = c;
    }//else

    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }//else

    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        mid = a;
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        mid = b;
    } else {
        mid = c;
    }//else

    printf("%d\n%d\n%d\n\n", min, mid, max);
    printf("%d\n%d\n%d\n", a, b, c);

    return 0;
}//main