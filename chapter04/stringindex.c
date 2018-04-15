#include <stdio.h>
#define MAXLINE 1000

/**
 *  Author:Zheng Jun
 *  Date:2018/4/13 13:35
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

int stringindex(char s[], char const t[]){
	int j, k;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k] ; ++j,++k)
		{
			continue;
		}
		if (k > 0 && t[k] == '\0')
		{
			return i;
		}
	}
	return -1;
}

int strindex(int argc, char const *argv[])
{
	char line[MAXLINE];
	int found = 0;
	while(getlinezj(line, MAXLINE) > 0){
		if (stringindex(line, argv[1]) > 0)
		{
			printf("找到的含有“%s”的行： %s\n", argv[1], line);
			found++;
		}
	}
	return 0;
}

	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ gcc -o strindex stringindex.c 
	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ ./strindex jun
	// /**
	//  *  Author:Zheng Jun
	//  *  Date:2018/4/13 13:35
	//  *  E-mail:zhengjun1987@outlook.com
	//  *  Desc:
	//  */
	// 找到的含有“jun”的行：  *  E-mail:zhengjun1987@outlook.com
	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ ./strindex jun
	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ gcc -o strindex stringindex.c 
	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ ./strindex jun
	// 找到的含有“jun”的行：  */zhengjuns-MacBook-Pro:chapter04 zhengjun$ ./strindex jun
	// 找到的含有“jun”的行： zhengjuns-MacBook-Pro:chapter04 zhengjun$ gcc -o strindex stringindex.c 

	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ ./strindex ould
	// Ah Love!Could you and I with Fate conspire
	// To grasp this sorry Scheme of Things entire,
	// Would not we shatter it to bits -- and then
	// Re-mould it nearer to the Heart's Desire.
	// 找到的含有“ould”的行： Ah Love!Could you and I with Fate conspire
	// 找到的含有“ould”的行： Would not we shatter it to bits -- and then
	// 找到的含有“ould”的行： Re-mould it nearer to the Heart's Desire.


