#include <stdio.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/12 13:03
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

int wrds(){
	int c,i,nWhite,nOther,nDigit[10];
	nOther = nWhite = 0;
	for (int i = 0; i < 10; ++i){
		nDigit[i] = 0;
	}
	while((c = getchar())!=EOF){
		switch(c){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				nDigit[c - '0']++;
				break;
			case ' ':
			case '\n':
			case '\t':
				nWhite++;
				break;
			default:
				nOther++;
				break;
		}
	}
	printf("digits = ");
	for (int i = 0; i < 10; ++i){
		printf("%d ", nDigit[i]);
	}
	printf("\n");
	printf("white space = %d\n", nWhite);
	printf("others = %d\n", nOther);
	return 0;
}

	// #include <stdio.h>

	// /**
	//  *  Author:Zheng Jun
	//  *  Date:2018/4/12 13:03
	//  *  E-mail:zhengjun1987@outlook.com
	//  *  Desc:
	//  */

	// int main(){
	// 	int c,i,nWhite,nOther,nDigit[10];
	// 	nOther = nWhite = 0;
	// 	for (int i = 0; i < 10; ++i)
	// 	{
	// 		nDigit[i] = 0;
	// 	}
	// 	while((c = getchar())!=EOF){
	// 		switch(c){
	// 			case '0':
	// 			case '1':
	// 			case '2':
	// 			case '3':
	// 			case '4':
	// 			case '5':
	// 			case '6':
	// 			case '7':
	// 			case '8':
	// 			case '9':
	// 				nDigit[c - '0']++;
	// 				break;
	// 			case ' ':
	// 			case '\n':
	// 			case '\t':
	// 				nWhite++;
	// 				break;
	// 			default:
	// 				nOther++;
	// 				break;
	// 		}
	// 	}
	// 	printf("digits = ");
	// 	for (int i = 0; i < 10; ++i)
	// 	{
	// 		printf("%d ", nDigit[i]);
	// 	}
	// 	printf("\n");
	// 	printf("white space = %d\n", nWhite);
	// 	printf("others = %d\n", nOther);
	// 	return 0;
	// }
	// digits = 12 8 3 3 2 1 1 2 3 2 
	// white space = 209
	// others = 501