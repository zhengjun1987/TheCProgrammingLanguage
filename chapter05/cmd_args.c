#include <stdio.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/18 20:06
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 int main(int argc, char const *argv[])
 {
 	for (int i = 0; i < argc; ++i)
 	{
 		printf("%s%s", argv[i], (i < argc - 1) ? " " : "\n");
 	}
 	return 0;
 }

	// zhengjuns-MacBook-Pro:chapter05 zhengjun$ gcc -o cmd cmd_args.c 
	// zhengjuns-MacBook-Pro:chapter05 zhengjun$ ./cmd arg1 arg2 arg3
	// ./cmd arg1 arg2 arg3