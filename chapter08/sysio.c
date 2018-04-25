#include <unistd.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/25 17:48
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 #define BUFSIZE 100

int main(int argc, char const *argv[])
{
	char buf[BUFSIZE];
	int n;
	while((n = read(0, buf, BUFSIZE)) > 0){
		write(1, buf, n);
	}
	return 0;
}