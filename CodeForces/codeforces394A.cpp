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

inline void print(int n){ while (n--) printf("|"); }

string s;
int a[3];
void solve(){
    memset(a, 0, sizeof(a));
    int j = 0;
    int sz = s.size();
    for (int i = 0; i < sz; i++){
        if (s[i] == '|') a[j]++;
        else j++;
    }
    //for (int i = 0; i < 3; i++){
    //    printf("%c = %d, ", 'A'+i, a[i]);
    //}
    //printf("\n");
    if ( (a[0]) + (a[1]) == (a[2]) ){
        print(a[0]);
        printf("+");
        print(a[1]);
        printf("=");
        print(a[2]);
        printf("\n");
        return;
    }
    else if ( (a[0] + 1) + (a[1] - 1) == (a[2]) && a[1] >= 2){
        print(a[0] + 1);
        printf("+");
        print(a[1] - 1);
        printf("=");
        print(a[2]);
        printf("\n");
        return;
    }
    else if ( (a[0] + 1) + (a[1]) == (a[2] - 1) && a[2] >= 2){
        print(a[0] + 1);
        printf("+");
        print(a[1]);
        printf("=");
        print(a[2] - 1);
        printf("\n");
        return;
    }
    else if ( (a[0] - 1) + (a[1] + 1) == (a[2]) && a[0] >= 2){
        print(a[0] - 1);
        printf("+");
        print(a[1] + 1);
        printf("=");
        print(a[2]);
        printf("\n");
        return;
    }
    else if ( (a[0] - 1) + (a[1]) == (a[2] + 1) && a[0] >= 2){
        print(a[0] - 1);
        printf("+");
        print(a[1]);
        printf("=");
        print(a[2] + 1);
        printf("\n");
        return;
    }
    else if ( (a[0]) + (a[1] + 1) == (a[2] - 1) && a[2] >= 2){
        print(a[0]);
        printf("+");
        print(a[1] + 1);
        printf("=");
        print(a[2] - 1);
        printf("\n");
        return;
    }
    else if ( (a[0]) + (a[1] - 1) == (a[2] + 1) && a[1] >= 2){
        print(a[0]);
        printf("+");
        print(a[1] - 1);
        printf("=");
        print(a[2] + 1);
        printf("\n");
        return;
    }
    else printf("Impossible\n");
}

int main(){
    while (getline(cin, s)) solve();
    return 0;
}