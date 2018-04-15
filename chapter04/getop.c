#include <ctype.h>
#include "getch.c"
/** 
 *  Author:Zheng Jun 
 *  Date: 2018-04-14 16:34
 *  E-mail:zhengjun1987@outlook.com 
 *  Desc: 
 */

int getch(void);
void ungetch(int);


int getop(char s[]){
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')/* 不是数字 */
	{
		return c;
	}
	i = 0;
	if (isdigit(c))
	{
		while(isdigit(s[++i] = c = getch()))/* 整数部分 */
			;
	}
	if (c == '.')
	{
		while(isdigit(s[++i] = c = getch()))/* 小数部分 */
			;
	}
	s[i] = '\0';
	if (c != EOF)
	{
		ungetch(c);
	}
	return '0';
}