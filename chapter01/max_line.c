/**
 *  Author:Zheng Jun
 *  Date:2018/4/11 01:36
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

#include <stdio.h>

#define MAX_LINE 1000
char line[MAX_LINE];
char longest[MAX_LINE];
int max = 0;

int getmaxline() {
    int i, c;
    for (i = 0; i < MAX_LINE - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy() {
    extern char line[];
    extern char longest[];
    int i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}

int main() {
    int len = 0;
    while ((len = getmaxline()) > 0) {
        if (len > max) {
            copy();
            max = len;
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

//        zhengjuns-MacBook-Pro:chapter01 zhengjun$ gcc -o maxl max_line.c
//        zhengjuns-MacBook-Pro:chapter01 zhengjun$ ./maxl
//        int main() {
//            char line[MAX_LINE];
//            char longest[MAX_LINE];
//            int len, max = 0;
//            while ((len = getmaxline(line, MAX_LINE)) > 0) {
//                if (len > max) {
//                    copy(longest, line);
//                    max = len;
//                }
//            }
//            if (max > 0) {
//                printf("%s", longest);
//            }
//            return 0;
//        }
//            while ((len = getmaxline(line, MAX_LINE)) > 0) {
