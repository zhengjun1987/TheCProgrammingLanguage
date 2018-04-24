#include <stdio.h>
#include <ctype.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/24 15:19
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */
 void filecopy(FILE *ifp, FILE *ofp){
 	int c;
 	while((c = getc(ifp)) != EOF){
 		putc(tolower(c), ofp);
 	}
 }

 int main(int argc, char const *argv[])
 {
 	FILE *fp;
 	char const *s = argv[0];
 	if (argc == 1)
 	{
 		filecopy(stdin, stdout);
 	} else {
 		while(--argc > 0){
 			if ((fp = fopen(*++argv,"r")) == NULL)
 			{
 				fprintf(stderr, "%s: cannot open %s\n", s, *argv);
 				exit(1);
 			} else {
 				filecopy(fp, stdout);
 				fclose(fp);
 			}
 		}
 	}
 	if (ferror(stdout))
 	{
 		fprintf(stderr, "%s: error writing stdout\n", s);
 		exit(2);
 	}
 	exit(0);
 }