#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alloc.c"
#include "strcopy.c"

#define MAXLINE 5000
char *lineptr[MAXLINE];

/**
 *  Author:Zheng Jun
 *  Date:2018/4/19 10:35
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

#define MAXLEN 1000

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

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while((len = getlinezj(line, MAXLEN)) > 0){
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
		{
			return -1;
		} else {
			line[len - 1] = '\0';
			strcopy(p,line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	for (int i = 0; i < nlines; ++i)
	{
		printf("%s\n", lineptr[i]);
	}
}

void swap(void *v[],int i, int j){
	void *temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsortzj(void *v[], int left, int right, int (*comparator)(void *, void *)){
	if (left >= right)
	{
		return;
	}
	int last = (left + right)/2;
	swap(v, left, last);
	last = left;
	for (int i = left + 1; i <= right; ++i)
	{
		if (comparator(v[i],v[left]) < 0)
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsortzj(v, left, last - 1, comparator);
	qsortzj(v, last + 1, right, comparator);
}

int numcmp(const char *s1,const char *s2){
	double v1 = atof(s1);
	double v2 = atof(s2);
	if (v1 > v2)
	{
		return 1;
	} else if (v1 < v2)
	{
		return -1;
	} else {
		return 0;
	}
}

int funptx(int argc, char const *argv[])
{
	int numeric = 0;
	if (argc > 1 && strstr(argv[1], "-n") != NULL)
	{
		numeric = 1;
	}
	int nlines;
	if ((nlines = readlines(lineptr, MAXLINE)) >= 0)
	{
		qsortzj((void **)lineptr, 0, nlines - 1,
			(int (*)(const void *,const void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

	// zhengjuns-MacBook-Pro:chapter05 zhengjun$ gcc -o funptx function_ptr.c 
	// function_ptr.c:107:4: warning: incompatible function pointer types passing 'int (*)(const void *, const void *)' to parameter of type
	//       'int (*)(void *, void *)' [-Wincompatible-function-pointer-types]
	//                         (int (*)(const void *,const void *))(numeric ? numcmp : strcmp));
	//                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// function_ptr.c:62:52: note: passing argument to parameter 'comparator' here
	// void qsortzj(void *v[], int left, int right, int (*comparator)(void *, void *)){
	//                                                    ^
	// 1 warning generated.
	// zhengjuns-MacBook-Pro:chapter05 zhengjun$ ./funptx
	// 1
	// 3
	// 2
	// 6
	// 4
	// 5
	// 9
	// 7
	// 8

	// ^D
	// 1
	// 2
	// 3
	// 4
	// 5
	// 6
	// 7
	// 8
	// 9