#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
    int i;
    for (i = 0; i < len; i++)
        printf("%p\t0x%.2x\n",start+i, start[i]);
    printf("\n");
}

void show_short(short inp){
    show_bytes((byte_pointer) &inp, sizeof(short));
}

void show_long(long inp){
    show_bytes((byte_pointer) &inp, sizeof(long));
}

void show_double(double inp){
    show_bytes((byte_pointer) &inp, sizeof(double));
}

int is_little_endian(void) {
    short test = 1;
    return *(char *)&test;
}


int testn(int a, unsigned int n) {
  return !!(a & (1 << n));
}

int main(void) {
    /*
    int a = -1;
    printf("int a = %d;\n", a);
    show_bytes((byte_pointer) &a, sizeof(int)); 
    show_short((short)424242);
    show_long((long)424242);
    show_double((double)424242);*/


    // int val = 0x87654321;
    // byte_pointer valp = (byte_pointer) &val;
    // show_bytes(valp, 1); /* A. */
    // show_bytes(valp, 2); /* B. */
    // show_bytes(valp, 3); /* C. */

    // const char *s = "abcdef";
    // show_bytes((byte_pointer) s, strlen(s));

    printf("%d\n", is_little_endian());

    
    // unsigned int x = 100;
    // printf("%d\n", !!x);
      
    // x = 0;
    // printf("%d\n", !!x);

    // x = 100;
    // printf("%d\n", !!(~x));

    // x = 0;
    // printf("%d\n", !!(~x));

    // x = 0xFFFFFFFF;
    // printf("%d\n\n", !!(~x));

    // x = 0xFF000000;
    // printf("%d\n", !!(x<<24));

    // x = 100;
    // printf("%d\n", !!(x<<24));
      
    // x = 0;
    // printf("%d\n", !!(x<<24));

    // x = 0xFF000000;
    // printf("%d\n", !!(x>>24));

    // x = 100;
    // printf("%d\n", !!(x>>24));
      
    // x = 0;
    // printf("%d\n", !!(x>>24));
    return 0;
}

