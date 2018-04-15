#include <stdio.h>
#define BUFSIZE 100

/**
 *  Author:Zheng Jun
 *  Date:2018/4/15 14:23
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 char buf[BUFSIZE];
 int bufp = 0;

 int getch(void){
 	return bufp > 0 ? buf[--bufp] : getchar();
 }

 void ungetch(int c){
 	if (bufp >= BUFSIZE)
 	{
 		printf("ungetch: too many characters\n");
 	} else {
 		buf[bufp++] = c;
 	}
 }