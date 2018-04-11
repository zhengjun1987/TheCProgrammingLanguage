/**
 *  Author:Zheng Jun
 *  Date:2018/4/11 01:09
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

#include <stdio.h>

/**
 * 函数声明可以省略
 * */
//int power(int base,int n);

int power(int base,int n){
    int p = 1;
    for (int i = 0; i < n; ++i) {
        p *= base;
    }
    return p;
}

int pow(){
    for (int i = 0; i < 10; ++i) {
        printf("%d %8d %8d\n",i, power(2,i), power(-3,i));
    }
    return 0;
}
//zhengjuns-MacBook-Pro:chapter01 zhengjun$ ./pow
//0        1        1
//1        2       -3
//2        4        9
//3        8      -27
//4       16       81
//5       32     -243
//6       64      729
//7      128    -2187
//8      256     6561
//9      512   -19683