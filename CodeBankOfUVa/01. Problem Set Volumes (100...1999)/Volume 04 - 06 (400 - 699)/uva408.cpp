//408
#include <cstdio>
int gcd(int a, int b)
{
	return (b == 0)? a: gcd(b, a % b);
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF){
		printf("%10d%10d", n, m);
		if (gcd(n, m) == 1)
			printf("    Good Choice\n\n");
		else
			printf("    Bad Choice\n\n");
	}
	return 0;
}
