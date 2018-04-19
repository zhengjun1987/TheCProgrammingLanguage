#include <stdio.h>
#include <string.h>
#include "alloc.c"
#include "strcopy.c"

/**
 *  Author:Zheng Jun
 *  Date:2018/4/16 15:16
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 #define MAXLINES 5000

 char *lineptr[MAXLINES];
 // int readlines(char *lineptr[], int nlines);
 // void writelines(char *lineptr[], int nlines);
 // void qsort(char *lineptr[], int left, int right);


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

 void swap(char *lineptr[], int i, int j){
 	char *temp = lineptr[i];
 	lineptr[i] = lineptr[j];
 	lineptr[j] = temp;
 }

 void qsort(char *lineptr[], int left, int right){
 	if (left >= right)
 	{
 		return;
 	}
 	int last = (left + right) / 2;
 	swap(lineptr, left, last);
 	last = left;
 	for (int i = left + 1; i <= right; ++i)
 	{
 		if (strcmp(lineptr[i], lineptr[left]) < 0)
 		{
 			swap(lineptr, i, ++last);
 		}
 	}
 	swap(lineptr,left, last);
 	qsort(lineptr, left, last - 1);
 	qsort(lineptr, last + 1, right);
 }

 int text_sort(int argc, char const *argv[])
 {
 	int nlines;
 	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
 	{
 		qsort(lineptr, 0, nlines - 1);
 		writelines(lineptr, nlines);
 	} else {
 		printf("error: input too big to  sort\n");
 	}
 	return 0;
 }