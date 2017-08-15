/****
	*@PoloShen
	*Title:C
	*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize ("O2")

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

int n;
bool M[1005][1005];
int q;
bool ans = 0;

void setMatrix(){
    for (int i = 0; i < n; i++)
        if (M[i][i])
            ans = !ans;
}

void CallPro1(){
    int i; scanf("%d", &i);
    i--;
    //for (int j = 0; j < n; j++)
    //    M[i][j] = !M[i][j];
    M[i][i] = !M[i][i];
    ans = !ans;
}

void CallPro2(){
    int j; scanf("%d", &j);
    j--;
    //for (int i = 0; i < n; i++)
    //    M[i][j] = !M[i][j];
    M[j][j] = !M[j][j];
    ans = !ans;
}

void CallPro3(){
    printf("%d", ans);
}

void solve(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    setMatrix();
    scanf("%d", &q);
    while (q--){
        int flag;
        scanf("%d", &flag);
        switch (flag){
            case 1:{ CallPro1(); break; }
            case 2:{ CallPro2(); break; }
            case 3:{ CallPro3(); break; }
            default: break;
        }
    }
    printf("\n");
    return;
}

int main(){
    //freopen("a.txt", "w", stdout);
    solve();
    return 0;
}
