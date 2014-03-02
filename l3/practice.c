#include <stdio.h>
//Practice Problem 2.44


short int_shifts_are_arithmetic (void) {
    short test = -12;
    return (test >> 1) < 0;
}

int any_odd_one (unsigned int x) {
    x = x & 0xAAAAAAAA;
    return x != 0;
}

int fits_bits(int x, int n) {
    int count = 8*sizeof(int) - n;
    return ((x << count) >> count) == x;
}

int tsub_ok(int x, int y) {
    int diff = x - y;
    int over = x > 0 && y < 0 && diff < 0;
    int under = x < 0 && y > 0 && diff > 0;
    return !over && !under; 
}

unsigned f2u (float n) {
    float *p = &n;
    return *((unsigned *)p);
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy, sx, and sy */
    return (sx && !sy) ||             /* x < 0, y >= 0 */
    ((ux<<1) == 0 && (uy<<1) == 0) || /* Both are zero */
    (!sx && !sy && ux <= uy) ||       /* x >= 0, y >= 0 */
    (sx && sy && ux >= uy);           /* x < 0, y < 0 */
}

int main(void) {

    //printf("%d\n", int_shifts_are_arithmetic());
    //printf("%d\n", any_odd_one(162));
    //printf("%d\n", fits_bits(4, 4));
    //printf("%d\n", tsub_ok(-2000000000, 23));
    printf("%x\n", float_le(-6.3, -8.3));
    return 0;
}
