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
	#include "F:\\My Source Code\\debug.h"
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

double p, u, i;
const char Concept[3] = {'P', 'U', 'I'};
const char Unit[3] = {'W', 'V', 'A'};

struct question{
	char Name;
	double Value;
	question(){Name = '\0';Value = -1;}
};
question telled[2];

void SetUpDataField(string& buf){
	int sz = buf.size();
	int quesnum = 0;
	for (int i = 0; i < sz; i++){
		for (int quesflag = 0; quesflag < 3; quesflag++){
			if (buf[i] == Concept[quesflag]){
				telled[quesnum].Name = buf[i];
				char sbuf[20];memset(sbuf, '\0', sizeof(sbuf));
				int iter = i + 2, j;//+2的意思是把指针后移两位，这样就把等号“=”也一并不用考虑了
				for (j = 0; !isalpha(buf[iter + j]); j++){
					sbuf[j] = buf[iter + j];
				}
				sscanf(sbuf, "%lf", &telled[quesnum].Value);
				switch (buf[iter + j]){
					case 'm':{telled[quesnum].Value /= 1000;break;}
					case 'k':{telled[quesnum].Value *= 1000;break;}
					case 'M':{telled[quesnum].Value *= 1000000;break;}
					default :break;
				}
				if (telled[quesnum].Value != -1)quesnum++;
			}
		}
		if (quesnum == 2)break;
	}
	return;
}

double Calu(int& ansflag){
	bool aflag[3];
	memset(aflag, 0, sizeof(aflag));
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			if (telled[i].Name == Concept[j]){
				aflag[j] = 1;
			}
		}
	}
	for (int i = 0; i < 3; i++){
		if (aflag[i] == 0){
			ansflag = i;
			break;
		}
	}
	double ans = 0;
	switch(ansflag){
		case 0:{ans = telled[0].Value * telled[1].Value;break;}
		case 1:{
			double num1 = (telled[0].Name == 'P')? telled[0].Value: telled[1].Value;
			double num2 = (telled[0].Name == 'I')? telled[0].Value: telled[1].Value;
			ans = num1 / num2;
			break;
		}
		case 2:{
			double num1 = (telled[0].Name == 'P')? telled[0].Value: telled[1].Value;
			double num2 = (telled[0].Name == 'U')? telled[0].Value: telled[1].Value;
			ans = num1 / num2;
			break;
		}
		default :break;
	}
	return ans;
}

void Print(int casenum, int ansflag, double ans){
	printf("Problem #%d\n", casenum);
	printf("%c=%.2lf%c\n", Concept[ansflag], ans, Unit[ansflag]);
	printf("\n");
	return;
}

void Solve(int casenum){
	int ansflag = 0;
	string buf;getline(cin, buf);
	SetUpDataField(buf);
	double ans = Calu(ansflag);
	Print(casenum, ansflag, ans);
}

int main(){
	int T, tt = 0;
	scanf("%d", &T);
	getchar();//消除回车
	while (T--){
		Solve(++tt);
	}
    return 0;
}
