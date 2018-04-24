#include <stdio.h>
#include <ctype.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/23 17:10
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 int main(int argc, char const *argv[])
 {
 	int c;
 	while((c = getchar()) != EOF){
 		putchar(tolower(c));
 	}
 	return 0;
 }


	// zhengjuns-MacBook-Pro:chapter07 zhengjun$ gcc -o lower lower.c 
	// zhengjuns-MacBook-Pro:chapter07 zhengjun$ ./lower <upper.txt 
	// sublime text 
	// file edit selection 
	// find view goto 
	// tools project window
 	// zhengjuns-MacBook-Pro:chapter07 zhengjun$ ./lower <upper.txt >lower.txt