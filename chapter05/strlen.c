/**
 *  Author:Zheng Jun
 *  Date:2018/4/16 11:00
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 int strlen(char *p){
 	int n;
 	for (n = 0; *p != '\0'; ++p)
 	{
 		n++;
 	}
 	return n;
 }