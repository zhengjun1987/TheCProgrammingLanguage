#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/**
 *  Author:Zheng Jun
 *  Date:2018/4/19 09:57
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

int getlinezj(char s[], int lim){
	int c, i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
		s[i++] = c;
	}
	if (c == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int findnx(int argc, char const *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	while(--argc > 0 && (*++argv)[0] == '-'){
		while(c = *++argv[0]){
			switch(c){
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
		}
	}
	if (argc != 1)
	{
		printf("Usage: find -x -n pattern\n");
	} else {
		while(getlinezj(line, MAXLINE) > 0){
			lineno++;
			if ((strstr(line, *argv) != NULL) != except)
			{
				if (number)
				{
					printf("%ld:", lineno);
				}
				printf("%s\n", line);
				found++;
			}
		}
	}
	return found;
}


	// zhengjuns-MacBook-Pro:chapter05 zhengjun$ ./find -n jun
	// /**
	//  *  Author:Zheng Jun
	//  *  Date:2018/4/19 09:57
	//  *  E-mail:zhengjun1987@outlook.com
	//  *  Desc:
	//  */
	// 4: *  E-mail:zhengjun1987@outlook.com

	// ^C