#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	for (int ti = 1; ti <= n; ti++){
		int sum, cnt = 0;
		scanf("%d", &sum);
		printf("Case #%d: %d", ti, sum);
		for (int i = 2; i * i <= sum; i++){
			if (cnt > 1)
				break;
			if (sum % i == 0){
				cnt++;
				printf(" = %d * %d", i, sum / i);
			}
		}
		printf("\n");
	}
	return 0;
}