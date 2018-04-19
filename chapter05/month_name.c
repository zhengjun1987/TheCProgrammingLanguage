/**
 *  Author:Zheng Jun
 *  Date:2018/4/18 12:44
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 char *month_name(int n){
 	static char *names[] = {
 		"Illegal month","Janauary", "February", "March", "April", "May", "June", "July", "August","September", "October", "November","December"
 	};
 	return (n <= 0 || n > 12) ? names[0] : names[n];
 }