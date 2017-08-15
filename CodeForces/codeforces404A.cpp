/****
	*@PoloShen
	*Title:A
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <algorithm>
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

typedef long long int64;

char input[305][305];

void solve(int n){
	char id, su;
	for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> input[i][j];
    id = input[0][0];
    su = input[0][1];
    if (id == su) { printf("NO\n"); return; }
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++){
            if (i == j || j == (n - 1 - i)){
                if (input[i][j] == id) continue;
                else { printf("NO\n"); return; }
            }
            else{
                if (input[i][j] == su) continue;
                else { printf("NO\n"); return; }
            }
        }
    }
    printf("YES\n");
    return;
}

int main(){
	int n; cin >> n;
	solve(n);
    return 0;
}