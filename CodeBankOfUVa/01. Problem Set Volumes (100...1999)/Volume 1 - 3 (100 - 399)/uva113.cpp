/****
	*@PoloShen
	*Title:UVa 113
	*/
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    double n, p;
    while (scanf("%lf%lf", &n, &p) != EOF) {
        printf("%.lf\n", pow(p, 1/n));
    }
    return 0;
}