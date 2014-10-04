/****
	*@PoloShen
	*Title:UVa 573
	*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
double H, U, D, F;

void solve(){
    double height = 0, down = U * F / 100.0;
    int cnt = 1;
    while (1){
        if (U > 0) height += U;
        if (height > H) {printf("success on day %d\n",cnt);break;}
        height -= D;
        U -= down;
        if (height < 0) {printf("failure on day %d\n",cnt);break;}
        cnt++;
    }
}

int main(){
    while (scanf("%lf%lf%lf%lf",&H,&U,&D,&F) != EOF){
        if (H==0 && U==0 && D==0 && F==0) break;
        solve();
    }
    return 0;
}