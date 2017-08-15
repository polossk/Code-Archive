/****
	*@PoloShen
	*Title:D
	*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int arr[1005];
int n;

void solve(){
    for (int i = 0; i < n; i++){ scanf("%d", &arr[i]); }
    sort(arr, arr + n);
    int l = 0, r = 0, ans = 2000000000;
    int ar0 = 0, det = 0;
    for (int d = 0; d < 20001; d++){
        l = r = 0;
        for (int i = 1; i < n; i++){
            l = min(l, arr[0] + i * d - arr[i]);
            r = max(r, arr[0] + i * d - arr[i]);
        }
        int pos = arr[0];
        l = -l;
        if (l < r){
            int mid = (l + r) / 2 - l;
            l += mid; r -= mid; pos -= mid;
        }
        if (r < l){
            int mid = (l + r) / 2 - r;
            l -= mid; r += mid; pos += mid;
        }
        l = -l;
        while (-l < r){ l--; r--; pos--; }
        while (-l > r){ l++; r++; pos++; }
        if (ans > r){ ans = r; ar0 = pos; det = d; }
    }
    printf("%d\n", ans);
    printf("%d %d\n", ar0, det);
}

int main(){
    scanf("%d", &n); solve();
    return 0;
}