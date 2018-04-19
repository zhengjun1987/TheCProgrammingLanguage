#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/**
 *  Author:Zheng Jun
 *  Date:2018/4/18 20:24
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

int find(int argc, char const *argv[])
{
	char line[MAXLINE];
	int found = 0;
	if (argc != 2)
	{
		printf("Usage: find pattern\n");
	} else {
		while(getlinezj(line, MAXLINE) > 0){
			/* 标准库函数strstr(char *s, char *t)返回一个指针，
			 * 指向字符串t在字符串s中第一次出现的位置
			 */
			if (strstr(line, argv[1]) != NULL)
			{
				printf("%s\n", line);
				found++;
			}
		}
	}
	return found;
}