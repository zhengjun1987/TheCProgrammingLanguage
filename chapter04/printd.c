#include <stdio.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/15 16:57
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 /* 打印十进制整数n */
 void printd(int n){
 	if (n < 0)
 	{
 		putchar('-');
 		n = -n;
 	}
 	if (n / 10)
 	{
 		printd(n / 10);
 	}
 	putchar(n % 10 + '0');
 }