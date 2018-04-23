#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../chapter04/getch.c"

#define MAXWORD 10
#define NKEYS 32

/**
 *  Author:Zheng Jun
 *  Date:2018/4/19 13:12
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

struct key
{
	char *word;
	int count;
};

struct key keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"do", 0},
	{"double", 0},
	{"else", 0},
	{"enum", 0},
	{"extern", 0},
	{"float", 0},
	{"for", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"long", 0},
	{"register", 0},
	{"return", 0},
	{"short", 0},
	{"signed", 0},
	{"sizeof", 0},
	{"static", 0},
	{"struct", 0},
	{"switch", 0},
	{"typedef", 0},
	{"union", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0},
};

int getword(char *word, int lim){
	int c;
	char *w = word;
	while(isspace(c = getch())){

	}
	if (c != EOF)
	{
		*w++ = c;
	}
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for( ; --lim > 0; w++){
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

int binsearch(char *word,struct key *keytab, int n){
	int cond;
	int low = 0, high = n - 1, mid;
	while(low <= high){
		mid = (low + high) / 2;
		if ((cond = strcmp(word, keytab[mid].word)) < 0)
		{
			high = mid - 1;
		} else if(cond > 0){
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	char word[MAXWORD];
	while(getword(word, MAXWORD) != EOF){
		if (isalpha(word[0]))
		{
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
			{
				keytab[n].count++;
			}
		}
	}
	for (int i = 0; i < NKEYS; ++i)
	{
		if (keytab[i].count > 0)
		{
			printf("%4d %s\n", keytab[i].count, keytab[i].word);
		}
	}
	return 0;
}

	// zhengjuns-MacBook-Pro:chapter06 zhengjun$ ./keys
	//  char buf[BUFSIZE];
	//  int bufp = 0;

	//  int getch(void){
	//  	return bufp > 0 ? buf[--bufp] : getchar();
	//  }

	//  void ungetch(int c){
	//  	if (bufp >= BUFSIZE)
	//  	{
	//  		printf("ungetch: too many characters\n");
	//  	} else {
	//  		buf[bufp++] = c;
	//  	}
	//  }
	//    1 char
	//    1 else
	//    1 if
	//    3 int
	//    1 return
	//    2 void
	// Abort trap: 6