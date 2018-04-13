#include <printf.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/12 08:56
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */
int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (v[mid] > x) {
            high = mid - 1;
        } else if (v[mid] < x) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }
    printf("binsearch(7,arr,10) = %d\n", binsearch(7,arr,10));
    return 0;
}
//    zhengjuns-MacBook-Pro:chapter03 zhengjun$ gcc -o bs binsearch.c
//    zhengjuns-MacBook-Pro:chapter03 zhengjun$ ./bs
//    binsearch(7,arr,10) = 6
