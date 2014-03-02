#include <stdio.h>
#include <assert.h>

/* Declarations of functions implementing operations bis and bic */
int bis(int x, int m){
    return x | m;
}
int bic(int x, int m) {
    return x & (~m);
}
/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
    int result = bis(x ,y);
    return result;
}
/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
    int result = bis(bic(~0, bis(bic(~0, x), y)), bic(~0, bis(x, bic(~0, y))));
    //int result = bis(bic(x, y), bic(y, x));
    return result;
}

#define LENGTH 5
int main(void) {
    int a = 0x4200ab12, b = 0x0100ff00;
    printf("%.8x\n", bis(a, b));
    printf("%.8x\n", bic(a, b));

    assert(bool_or(a ,b) == (a|b));
    assert(bic(~0, a) == ~a);
    assert(bic(~0, b) == ~b);
    assert(bool_xor(a ,b) == (a^b));
    return 0;
}