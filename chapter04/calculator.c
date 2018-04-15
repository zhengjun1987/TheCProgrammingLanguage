#include <stdio.h>
#include <stdlib.h>
#include "getop.c"
#include "stack.c"

/**
 *  Author:Zheng Jun
 *  Date:2018/4/13 19:02
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 #define MAXOP 100
 #define NUMBER '0'

 int getop(char []);
 void push(double);
 double pop(void);

 int calct(int argc, char const *argv[])
 {
 	int type;
 	double op2;
 	char s[MAXOP];
 	while((type = getop(s))!= EOF){
 		switch(type){
 			case NUMBER:
 				push(atof(s));
 				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
				{
					push(pop()/op2);
				} else {
					printf("error: unknown command %s\n", s);
				}
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
				{
					push(pop() % op2);
				} else {
					printf("error: unknown command %s\n", s);
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
 		}
 	}
 	return 0;
 }

	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ gcc -o calct calculator.c 
	// zhengjuns-MacBook-Pro:chapter04 zhengjun$ ./calct 
	// 1 2 - 4 5 + *
	// 	-9
	// 159 2.333333 *
	// 	370.99995