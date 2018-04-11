#include <stdio.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/11 22:48
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

int ary() {
    int nWhite, nOther, nDigit[10], c;
    nWhite = nOther = 0;
    for (int i = 0; i < 10; ++i) {
        nDigit[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++nDigit[c - '0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++nWhite;
        } else {
            ++nOther;
        }
    }

    printf("digits = ");
    for (int j = 0; j < 10; ++j) {
        printf(" %d", nDigit[j]);
    }
    printf(", white space = %d ,other = %d\n", nWhite, nOther);
    return 0;
}
//int main() {
//    int nWhite, nOther, nDigit[10], c;
//    nWhite = nOther = 0;
//    for (int i = 0; i < 10; ++i) {
//        nDigit[i] = 0;
//    }
//    while ((c = getchar()) != EOF) {
//        if (c >= '0' && c <= '9') {
//            ++nDigit[c - '0'];
//        } else if (c == ' ' || c == '\n' || c == '\t') {
//            ++nWhite;
//        } else {
//            ++nOther;
//        }
//    }
//
//    printf("digits = ");
//    for (int j = 0; j < 10; ++j) {
//        printf(" %d",nDigit[j]);
//    }
//    printf(", white space = %d ,other = %d\n",nWhite,nOther);
//    return 0;
//}
//
//^D
//digits =  10 3 0 0 0 0 0 0 0 1, white space = 230 ,other = 318
//
//Process finished with exit code 0