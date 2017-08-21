/****
    *@PoloShen
    *Title:J
    */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int p[1010];

void solve(){
    string s;
    int m, i, j, pos;
    cin >> s >> m;
    int len = s.length();
    for (i = 0; i < s.length(); ++i) p[i] = s[i] - '0';
    int maxi = 10;
    int cnt = 0;
    if (m){
        for (i = 1; i < s.length(); ++i){
            if (p[i] < maxi && p[i] != 0){
                maxi = p[i];
                pos = i;
            }
        }
        if (maxi < p[0]) {
            swap(p[0],p[pos]);
            cnt++;
        }
        for (i = 1; i < len-1; ++i){
            maxi = 10;
            if (cnt == m) break;
            for (j = i + 1; j < len; ++j){
                if (p[j] < maxi){
                    maxi = p[j];
                    pos = j;
                }
            }
            if (maxi < p[i]){
                swap(p[i],p[pos]);
                cnt++;
            }
        }
    }
    for (i = 0; i < len; ++i) printf("%d", p[i]);
    printf("\n");
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}