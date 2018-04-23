#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/22 21:11
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 int main(int argc, char const *argv[])
 {
 	union {
 		int ival;
 		float fval;
 		char *sval;
 	} u_tag;
 	u_tag.ival = 1;
 	u_tag.sval = "Hello!";
 	printf("%d\n", u_tag.ival);
 	// printf("%d\n", (int)(typeof(u_tag))); //union.c:21:18: error: expected expression
 	// int t = typeof(u_tag);
 	// if (t == INT)
 	// {
 	// 	printf("t == INT\n");
 	// } else if (t == STRING)
 	// {
 	// 	printf("t == STRING\n");
 	// } else if (t == FLOAT)
 	// {
 	// 	printf("t == FLOAT\n");
 	// }

 	struct {
 		unsigned is_keyword : 1;
 		unsigned is_extern : 1;
 		unsigned is_static : 1;
 	} flags;

 	printf("sizeof(flags) = %lu\n", sizeof(flags));//4
 	printf("sizeof(u_tag) = %lu\n", sizeof(u_tag));//8

 	return 0;
 }