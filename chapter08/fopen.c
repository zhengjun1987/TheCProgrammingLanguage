#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/25 18:58
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */
 #define BUFSIZE 100
 #define PERMS 0666

 void error(char *fmt, ...){
 	va_list args;
 	va_start(args, fmt);
 	fprintf(stderr, "error: ");
 	vfprintf(stderr, fmt, args);
 	fprintf(stderr, "\n");
 	va_end(args);
 	exit(1);
 }

 int main(int argc, char const *argv[])
 {
 	int f1, f2, n;
 	char buf[BUFSIZE];

 	if (argc != 3)
 	{
 		error("Usage: cp from to");
 	}

 	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
 	{
 		error("cp: cannot open %s", argv[1]);
 	}

 	if ((f2 = create(argv[2], PERMS)) == -1)
 	{
 		error("cp: cannot create %s, mode %03o", argv[2], PERMS);
 	}

 	while((n = read(f1, buf, BUFSIZE)) > 0){
 		if (write(f2, buf, BUFSIZE) != n)
 		{
 			error("cp: write error on file %s", argv[2]);
 		}
 	}
 	return 0;
 }