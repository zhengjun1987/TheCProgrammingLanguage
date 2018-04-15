#include <stdio.h>
#include <ctype.h>
#include "stringindex.c"

/**
 *  Author:Zheng Jun
 *  Date:2018/4/13 16:48
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 double atof(char s[]){
 	double val, power;
 	int i, sign;
 	for (i = 0; isspace(s[i]); ++i)
 		;
 	sign = (s[i] == '-') ? -1: 1;
 	if (s[i] == '-' || s[i] == '+')
 	{
 		i++;
 	}
 	for(val = 0.0; isdigit(s[i]);i++){
 		val = 10 *val + s[i] - '0';
 	}
 	if (s[i]=='.')
 	{
 		i++;
 	}
 	for(power = 1.0;isdigit(s[i]);i++){
 		val = 10.0 * val + s[i] - '0';
 		power *= 10.0;
 	}
 	return sign * val / power;
 }

 int atf(int argc, char const *argv[])
 {
 	double sum;
 	char line[MAXLINE];
 	sum = 0;
 	while(getlinezj(line,MAXLINE)>0){
 		printf("\t%g\n", sum += atof(line));
 	}
 	return 0;
 }

	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ gcc -o atof atof.c 
	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ ./atof 
	// 3.14
	// 	3.14
	// 0.19
	// 	3.33
	// 1.414
	// 	4.744
	// 2.236
	// 	6.98
	// 1.732
	// 	8.712
	// 0.618
	// 	9.33
	// -9.33
	// 	0
	// 11
	// 	11
	// 99
	// 	110
	// 87
	// 	197
	// ^C
