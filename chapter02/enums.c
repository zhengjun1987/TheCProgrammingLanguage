#include <printf.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/12 01:57
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */
void squeeze(char s[], char c) {
    printf("string = %s\n", s);
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p - n)) & (~(~0 << n));
}

int enu() {
    enum months {
        Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec
    };
    for (int i = 0; i < 12; ++i) {
        printf("%d === %d\n", i + 1, Aug);
    }

    char s[] = "December";
    squeeze(s, 'e');
    printf("string = %s\n", s);
    for (int i = 0; i < 8; ++i) {
        printf("%d === %d\n", i + 1, s[i]);
    }

    printf(" getbits(15,3,2) = %d\n", getbits(15, 3, 2));
    printf(" ~0 = %d\n", ~0);
    printf(" ~((-1)>>1) = %d\n", ~((-1) >> 1));
    unsigned int x = (0b11111111111111111111111111111111 >> 1);
    printf(" x = %d\n", x);
    printf(" ~(((-1) >> 1) - 1) = %d\n", ~(x &= (x - 1)));
}