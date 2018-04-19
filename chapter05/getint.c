#include <ctype.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/16 10:08
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 int getch(void);
 void ungetch(int);

 int getint(int *pn){
 	int c, sign;
 	while(isspace(c = getch()))
 		;
 	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
 	{
 		ungetch(c);
 		return 0;
 	}
 	sign = (c == '-')? -1 : 1;
 	if (c == '+' || c == '-')
 	{
 		c = getch();
 	}
 	for (*pn = 0; isdigit(c); c = getch())
 	{
 		*pn = (*pn) * 10 + (c - '0');
 	}
 	*pn *= sign;
 	if (c != EOF)
 	{
 		ungetch(c);
 	}
 	return c;
 }