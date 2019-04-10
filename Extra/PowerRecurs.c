#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y, unsigned ans) {
    //Write function to calculate exponent
    if(y == 0) {
        return ans;
    }
    else {
        ans *= x;
        printf("ans is %d, x is %d, y is %d\n", ans, x, y);
        return power(x, y - 1, ans);
    }
}

void main() {
    printf("%d\n", power(10, 5, 1));
}