#include <stdarg.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/23 17:59
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 void minprintf(char *format, ...){
 	va_list ap;
 	char *p, *sval;
 	int ival;
 	double dval;

 	va_start(ap, format);
 	for(p = format; *p; p++){
 		if (*p != '%')
 		{
 			putchar(*p);
 			continue;
 		}
 		switch(*++p){
 			case 'd':
 				ival = va_arg(ap, int);
 				printf("%d", ival);
 				break;
 			case 'f':
 				dval = va_arg(ap, double);
 				printf("%f", dval);
 				break;
 			case 's':
 				for(sval = va_arg(ap, int); *sval; sval++){
 					putchar(*sval);
 				}
 				break;
 			default:
 				putchar(*p);
 				break;
 		}
 	}
 	va_end(ap);
 }