#include <stdio.h>
#include <ctype.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/12 14:05
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */
 int atoi2(const char s[]){
 	int i, n, sign;
 	for (i = 0; isspace(s[i]); ++i)
 		;
 	sign = (s[i] == '-') ? -1 : 1;
 	if (s[i] == '+' || s[i] == '-')
 	{
 		i++;
 	}
 	for (n = 0; isdigit(s[i]); ++i)
 	{
 		n = 10 * n + (s[i] - '0');
 	}
 	return sign * n;
 }

 void shellsort(int v[], int n){
 	int temp;
 	for (int gap = n/2; gap > 0; gap /= 2)
 	{
 		for (int i = gap; i < n; ++i)
 		{
 			for (int j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
 			{
 				temp = v[j];
 				v[j] = v[j + gap];
 				v[j + gap] = temp;
 			}
 		}
 	}
 }

 int shs(int argc, char const *argv[])
 {
 	int arr[argc - 1];
 	for (int i = 1; i < argc; ++i)
 	{
 		arr[i-1] = atoi2(argv[i]);
 	}
 	shellsort(arr, argc - 1);
 	for (int i = 0; i < argc - 1; ++i)
 	{
 		printf("%d ", arr[i]);
 	}
 	printf("\n");
 	return 0;
 }

	// zhengjuns-MacBook-Pro:chapter03 zhengjun$ gcc -o shs shellsort.c 
	// zhengjuns-MacBook-Pro:chapter03 zhengjun$ ./shs 8 1 3 23 11 90 2 8
	// 1 2 3 8 8 11 23 90