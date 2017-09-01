/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

const string Alice = "Alice";
const string Bob   = "Bob"  ;
int main(){
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++){
        int n;
        string st;
        printf("Case %d: ", tt);
        cin>>n>>st;
        if (st == Bob){
            /* If Bob starts first, then the player who takes the last marble wins the game. */
            if (n % 3 == 0){
                printf("Alice\n");
            }
            else{
                printf("Bob\n");
            }
        }
        else{
            /* If Alice starts first, then the player who takes the last marble looses the game. */
            if ((n-1) % 3 == 0){
                printf("Bob\n");
            }
            else{
                printf("Alice\n");
            }
        }
    }
    return 0;
}
