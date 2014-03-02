#include <stdio.h>

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first = 0, last = cnt-1;
    for (; first < last; first++,last--) {
        inplace_swap(&a[first], &a[last]);
    }
    
}



#define LENGTH 5
int main(void) {
    int nums[LENGTH] = {1, 2, 3, 4, 5};
    reverse_array(nums, LENGTH);
    int i = 0;
    for (; i < LENGTH; ++i) {
        printf("%d\n", nums[i]);
    }

    printf("%x\n", 0x87654321 | 0xFF);
    return 0;
}