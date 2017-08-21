/****
    *@PoloShen
    *Title:F
    */
#include <cstdio>
using namespace std;
short ans[5] = {0, 0, 18, 284, 4862};
short t, n;
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}