#include <stdio.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/24 00:03
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 int main(int argc, char const *argv[])
 {
 	double sum, v;
 	sum = 0;
 	while(scanf("%lf", &v) == 1){
 		printf("\t%.2f\n", sum += v);
 	}
 	return 0;
 }
	// zhengjuns-MacBook-Pro:chapter07 zhengjun$ gcc -o sum sum.c 
	// zhengjuns-MacBook-Pro:chapter07 zhengjun$ ./sum 
	// 12
	// 	12.00
	// 2089
	// 	2101.00
	// -99
	// 	2002.00
	// 19
	// 	2021.00
	// 1000 
	// 	3021.00
	// -2000 
	// 	1021.00
	// -2
	// 	1019.00
	// 0
	// 	1019.00
	// su