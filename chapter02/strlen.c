#include <string.h>
#include <printf.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/12 01:22
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:C语言对程序中的字符串常量在编译后是连续统一存放在一起的
 */

int str() {
    char *string = "1234567890";
    printf("strlen(string) = %ld\n", strlen(string));
    for (int i = 0; i < 50; ++i) {
        printf("%2d === %c\n", i, string[i]);
    }
    return 0;
}

//    zhengjuns-MacBook-Pro:chapter02 zhengjun$ gcc -o str strlen.c
//    zhengjuns-MacBook-Pro:chapter02 zhengjun$ ./str
//    strlen(string) = 10
//    0 === 1
//    1 === 2
//    2 === 3
//    3 === 4
//    4 === 5
//    5 === 6
//    6 === 7
//    7 === 8
//    8 === 9
//    9 === 0
//    10 ===
//    11 === s
//    12 === t
//    13 === r
//    14 === l
//    15 === e
//    16 === n
//    17 === (
//    18 === s
//    19 === t
//    20 === r
//    21 === i
//    22 === n
//    23 === g
//    24 === )
//    25 ===
//    26 === =
//    27 ===
//    28 === %
//    29 === l
//    30 === d
//    31 ===
//
//    32 ===
//    33 === %
//    34 === 2
//    35 === d
//    36 ===
//    37 === =
//    38 === =
//    39 === =
//    40 ===
//    41 === %
//    42 === c
//    43 ===
//
//    44 ===
//    45 ===
//    46 ===
//    47 ===
//    48 ===
//    49 ===
