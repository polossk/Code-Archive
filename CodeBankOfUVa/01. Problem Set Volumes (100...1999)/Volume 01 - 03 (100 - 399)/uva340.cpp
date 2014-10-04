#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxN = 1005;
int codeorigin[maxN], guess[maxN], code[maxN];
int st, wk;

void read(int n){
    for (int i = 0; i < n; ++i){
        scanf("%d", &codeorigin[i]);
    }
}

void cal(int n){
    while (1){
        st = wk = 0;
        int zeroflag = 0;
        for (int i = 0; i < n; ++i){
            scanf("%d", &guess[i]);
            if (guess[i] == 0)++zeroflag;
            if (guess[i] == codeorigin[i]){
                ++st;
                code[i] = -1;
                guess[i] = -1;
            }
            else code[i] = codeorigin[i];
        }
        if (zeroflag == n)return;
        for (int i = 0; i < n; ++i){
            if (guess[i] != -1){
                for (int j = 0; j < n; ++j){
                    if (guess[i] == code[j]){
                        ++wk;
                        code[j] = -1;
                        guess[i] = -1;
                        break;
                    }
                }
            }
        }
        printf("    (%d,%d)\n", st, wk);
    }
}

void solve(int casenum, int n){
    read(n);
    printf("Game %d:\n", casenum);
    cal(n);
}

int main(){
    int casenum = 0;
    int n;
    while (scanf("%d", &n) && n){
        solve(++casenum, n);
    }
    return 0;
}