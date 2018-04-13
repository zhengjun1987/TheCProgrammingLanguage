#include <stdio.h>
#include <string.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/12 14:43
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

void reverse(char s[]){
	int c;
	for (int i = 0,j = strlen(s)-1; i < j; i++,j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int rev(int argc, char const *argv[])
{
	int count = strlen(argv[1]);
	char s[count];
	for (int i = 0; i < count; ++i)
	{
		s[i] = argv[1][i];
	}
	reverse(s);
	printf("s = %s\n", s);
	return 0;
}

	// zhengjuns-MacBook-Pro:chapter03 zhengjun$ gcc -o rev reverse.c 
	// zhengjuns-MacBook-Pro:chapter03 zhengjun$ ./rev live
	// s = evil
