

/**
 *  Author:Zheng Jun
 *  Date:2018/4/17 13:35
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 static int daytab[2][13] = {
 	{0,31,28,31,30,31,30,31,31,30,31,30,31},
 	{0,31,29,31,30,31,30,31,31,30,31,30,31}
 }

 int day_of_year(int year, int yearday, int *pmonth, int *pday){
 	 int i， leap, res = 0;
 	 leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
 	 for (int i = 1; i < *pmonth; ++i)
 	 {
 	 	res += daytab[leap][i];
 	 }
 	 return res + *pday;
 }

 void month_day(int year, int yearday, int *pmonth, int *pday){
 	int i, leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
 	for (i = 1; yearday > daytab[leap][i] ; ++i)
 	{
 		yearday -= daytab[leap][i];
 	}
 	*pmonth = i;
 	*pday = yearday;
 }