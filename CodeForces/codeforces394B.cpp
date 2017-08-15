/****
	*@PoloShen
	*Title:B
	*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1000005;
int s[MAXN],t[MAXN];

void solve(int p, int x){
    for (int i = x; i <= 9; i++){
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        s[1] = i;
        for (int j = 1; j <= p; j++){
            t[j]     += s[j] * x;
            t[j + 1] += t[j] / 10;
            t[j]     %= 10;
            s[j + 1]  = t[j];
        }
        if (t[p+1] == 0 && s[p] != 0 && t[p] == i){
            for (int i = p; i > 0; i--) printf("%d",s[i]);
            printf("\n");
            return;
        }
	}
	printf("Impossible\n");
	return;
}

int main(){
	int p,x;
	scanf("%d%d", &p, &x);
    solve(p, x);
}