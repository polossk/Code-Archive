/****
	*@PoloShen
	*Title:
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

#define DBG 0
#define ALG 0
#define USING_STL_STRING	1
#define USING_STL_VECTOR	1
#define USING_STL_LIST		1
#define USING_STL_STACK		1
#define USING_STL_DEQUE		1
#define USING_STL_QUEUE		1

#if DBG
	#include "debug.h"
#else
	#define __DBG 0 &&
#endif // DBG

#if ALG
	#include <algorithm>
#else
	#ifndef min
		#define min(x,y) ((x) < (y) ? (x) : (y))
	#endif
	#ifndef max
		#define max(x,y) ((x) > (y) ? (x) : (y))
	#endif
#endif // ALG

const int maxa = 20;
const int maxc = 40;
const int maxn = 60;
double dp[2][maxn][3][maxa][maxc];
double b[2][3], d[2][3];

inline double P(int i, int j, int n){
    return max(0.0, min(1.0, b[i][j] - n * d[i][j]));
}//概率计算函数

double f(int id, int n, int m, int a, int c){
    double &res = dp[id][n][m][a][c];
    if (res >= 0) return res;//计算过res，不再考虑
    if (a == 0 && c == 0) return res = 0;//没有A和C，结束
    int n0 = n, a0 = a;
    if (m == 0) n++;
    if (m == 2) a++;
    m = (m + 1) % 3;
    res = 0;
    if (a0 > 0){
        res = max(res, P(id, 0, n0) * (1.0 - f(1-id, n, m, a-1, c)   ));
        res = max(res, P(id, 1, n0) * (1.0 - f(1-id, n, m, a-1, c+1) ));
    }
    if (c > 0){
        res = max(res, P(id, 2, n0) * (1.0 - f(1-id, n, m, a  , c-1)   ));
    }
    return res;
}//主要过程

int main(){
    int T, n;
    scanf("%d", &T);
    while (T--){
        //初始化
        for (int i=0;i<2;i++)
            for (int n=0;n<maxn;n++)
                for (int m=0;m<3;m++)
                    for (int a=0;a<maxa;a++)
                        for (int c=0;c<maxc;c++)
                            dp[i][n][m][a][c] = -1;
        //main
        scanf("%d", &n);
        for (int i=0;i<2;i++)
            for (int j=0;j<3;j++)
                scanf("%lf%lf", &b[i][j], &d[i][j]);
        printf("%.4lf\n", f(0, n, 0, n-1, 0));
    }
    return 0;
}
