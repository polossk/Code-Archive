/****
	*@author    Shen
	*@title     B
	*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma GCC optimize ("O2")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

typedef long long int64;

int n;
int m;
int a[3000];
int b[3000];

void solve(){
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf ("%d", &b[i]);
    for (int i = 0; i <= n; i++) {
        int ok = 1;
        for (int j = 0; j < n - i; j++)
            if (a[j] > b[m - (n - i) + j])
                ok = 0;
        if (ok) {
            printf ("%d\n", i);
            return;
        }
    }
}

int main () {
    scanf("%d%d", &n, &m);
    solve();
    return 0;
}
