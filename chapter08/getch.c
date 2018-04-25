#include <unistd.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/25 18:22
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 int getchar(void){
 	char c;
 	return (read(0, &c, 1) == 1 ? (unsigned char) c : EOF);
 }