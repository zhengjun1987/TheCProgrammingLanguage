#include <stdio.h>
#include <math.h>
#define min(a, b) ((a) > (b) ? (b) :(a))
#define max(a, b) ((a) < (b) ? (b) :(a))
#define print(a) printf(#a " = %d\n", a);
/**
 *  Author:Zheng Jun
 *  Date:2018/4/19 13:12
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 struct point
 {
 	int x;
 	int y;
 };

 double distance(struct point pt){
 	return sqrt((double)pt.x*pt.x + (double)pt.y*pt.y);
 }

 struct point makepoint(int x, int y){
 	struct point temp;
 	temp.x = x;
 	temp.y = y;
 	return temp;
 }

 struct rect
 {
 	struct point pt1;
 	struct point pt2;
 };

 int ptinrect(struct rect r, struct point p){
 	return p.x >= r.pt1.x && p.x < r.pt2.x
 		&& p.y >= r.pt1.y && p.y < r.pt2.y;
 }

 struct rect canonrect(struct rect r){
 	struct rect temp;
 	temp.pt1.x = min(r.pt1.x, r.pt2.x);
 	temp.pt1.y = min(r.pt1.y, r.pt2.y);
 	temp.pt2.x = max(r.pt1.x, r.pt2.x);
 	temp.pt2.y = max(r.pt1.y, r.pt2.y);
 	return temp;
 }

 int stru(int argc, char const *argv[])
 {
 	struct point maxpt =
 	{
 		320, 240
 	};
 	printf("maxpt.x = %d\n", maxpt.x);
 	print(maxpt.y);
 	printf("distance = %g\n", distance(maxpt));
 	return 0;
 }