#include <ctype.h>
#include <stdio.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/12 13:35
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 int atoi(char s[]){
 	int i, n, sign;
 	for (i = 0; isspace(s[i]); ++i)
 		;
 	sign = (s[i] == '-') ? -1 : 1;
 	if (s[i] == '+' || s[i] == '-')
 	{
 		i++;
 	}
 	for (n = 0; isdigit(s[i]); ++i)
 	{
 		n = 10 * n + (s[i] - '0');
 	}
 	return sign * n;
 }

 int at(int argc, char const *argv[])
 {
 	printf("argc = %d\n", argc);
 	for (int i = 0; i < argc; ++i)
 	{
 		printf("argv[%d] = %s\n", i, argv[i]);
 	}
 	char arr[6] = "-1000";

 	printf("atoi(arr) = %d\n", atoi(arr));
 	return 0;
 }

	// zhengjuns-MacBook-Pro:chapter03 zhengjun$ gcc -o atoi atoi.c 
	// zhengjuns-MacBook-Pro:chapter03 zhengjun$ ./atoi sec
	// argc = 2
	// argv[0] = ./atoi
	// argv[1] = sec
	// atoi(arr) = -1000