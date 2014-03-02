#include <stdio.h>
#include <limits.h>

unsigned rot_r(int x, unsigned count)
{
    return (unsigned) x >> count | x << (8 * sizeof(int) - count);
}


unsigned rot_l(int x, unsigned count)
{
    return x << count | (unsigned) x >> (8 * sizeof(int) - count);
}

//http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
//assumes little endian
void printBits(size_t const size, void const *const ptr)
{
    unsigned char *b = (unsigned char *) ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = b[i] & (1 << j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}

int rot_r_asm(int x, unsigned count)
{
    asm("ror %%cl, %[x]"
        : [x] "+r" (x)
        : "c" (count)
        : "cc");

    return x;
}

int rot_l_asm(int x, unsigned count)
{
    asm("rol %%cl, %[x]"
        : [x] "+r" (x)
        : "c" (count)
        : "cc");

    return x;
}

int add_asm(int a, int b)
{
    asm("add %[b], %[a]"
        : [a] "+r" (a)
        : [b] "r" (b)
        :);

    return a;
}

void set_asm(int * string, unsigned n) {
    asm("bts %[n], (%[string])"
        : 
        : [string] "r" (string), [n] "r" (n)
        : "cc", "memory");
}

void set(int * string, unsigned n) {
    int bit = n % 32;
    int word = n / 32;

    string[word] |= 1 << bit ;
}

int main(int argc, char const *argv[])
{
    int x = 843267973;
    int i;
    for (i = 0; i < 20; ++i)
    {
        printBits(sizeof(int), &x);
        x = rot_r_asm(x, 2);
    }

    for (i = 0; i < 20; ++i)
    {
        printBits(sizeof(int), &x);
        x = rot_l_asm(x, 2);
    }
    
    printf("%d\n", add_asm(234,235));

    int test[5] = {0};

    set(test, 0);
    set(test, 1);
    set(test, 3);
    set(test, 32);
    set(test, 33);
    set(test, 76);
    printBits(sizeof(int) * 5,test);

    x = INT_MIN;
    printf("%d\n", (x > 0) || (x-1 < 0));


    return 0;
}
