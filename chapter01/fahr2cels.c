#include <printf.h>

/**
 *  Author:Zheng Jun
 *  Date:2018/4/10 23:38
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

int f2c() {
    float fahr, cels;
    int lower = 0, upper = 300, step = 20;
    fahr = lower;
    while (fahr <= upper) {
        cels = (fahr - 32) * 5 / 9;
        printf("%6.2f\t%6.2f\n", fahr, cels);
        fahr += step;
    }
    return 0;
}
//    0	-17
//    20	 -6
//    40	  4
//    60	 15
//    80	 26
//    100	 37
//    120	 48
//    140	 60
//    160	 71
//    180	 82
//    200	 93
//    220	104
//    240	115
//    260	126
//    280	137
//    300	148
//
//Process finished with exit code 0


//    0.00	-17.78
//    20.00	 -6.67
//    40.00	  4.44
//    60.00	 15.56
//    80.00	 26.67
//    100.00	 37.78
//    120.00	 48.89
//    140.00	 60.00
//    160.00	 71.11
//    180.00	 82.22
//    200.00	 93.33
//    220.00	104.44
//    240.00	115.56
//    260.00	126.67
//    280.00	137.78
//    300.00	148.89
//
//    Process finished with exit code 0