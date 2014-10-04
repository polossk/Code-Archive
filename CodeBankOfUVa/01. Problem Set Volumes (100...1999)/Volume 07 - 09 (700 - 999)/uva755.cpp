/****
	*@PoloShen
	*Title:UVaOJ 755
	*/
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
char s[31];

int Hash(){
    int sum=0;
    for (int i = 0, k = 0; k < 7; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            sum *= 10;
            ++k;
            sum += (s[i] - '0');
        }
        else if(s[i] >= 'A' && s[i] < 'Z'){
            sum *= 10;
            ++k;
            sum += ((s[i] - 'A' - ( s[i] > 'Q' )) / 3 + 2);
        }
    }
    return sum;
}

void solve(int m){
    int n;
    scanf("%d",&n);
    vector<int> data;getchar();
    data.resize(n);
    for(int tmp = 0; tmp < n; ++tmp){
        gets(s);
        data[tmp] = Hash();
    }
    sort(data.begin(), data.end());
    bool p = 0;
    n--;
    for (int i = 0,num = 1; i < n;i += num = 1){
        while (data[i] == data[i+1]){
            num++;
            i++;
        }
        if (num>1){
            printf("%03d-%04d %d\n", data[i] / 10000, data[i] % 10000, num);
            p = 1;
        }
    }
    if (!p) printf("No duplicates.\n");
    if (m) printf("\n");
}

int main(){
    int m;scanf("%d", &m);
    while (m--) solve(m);
    return 0;
}