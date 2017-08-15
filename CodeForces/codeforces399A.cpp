/****
	*@PoloShen
	*Title:A
	*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int n, p, k;

void solve(){
	bool first = 1;
	if (p - k > 1) { printf("<<"); first = 0;}
	for (int i = 1; i <= n; i++){
        if (i == p)
        {
            if (first){ first = 0; printf("(%d)", p); }
            else printf(" (%d)", p);
        }
        else if (p - k <= i && i <= p + k){
            if (first){ first = 0; printf("%d", i); }
            else printf(" %d", i);
        }
        else continue;
	}
	if (p + k < n) printf(" >>\n");
	else printf("\n");
}

int main(){
    while (cin >> n >> p >> k) solve();
    return 0;
}