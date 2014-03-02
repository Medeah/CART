#include <stdio.h>

int
sec(int in) {
    return in + 2;
}


int
rec(int in) {
    in ++;
    return sec(in);
}
 


int
main(int argc, char const *argv[])
{
    printf("%d\n", rec(4));
    return 0;
}

