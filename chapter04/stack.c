#define MAXVAL 100

static int sp = 0;

/**
 *  Author:Zheng Jun
 *  Date:2018-04-14 16:09
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

static double val[MAXVAL];

void push(double f){
	if(sp < MAXVAL){
		val[sp++] = f;
	} else {
		printf("error: stack full, cannot push %g\n", f);
	}
}

double pop(){
	if (sp > 0)
	{
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}