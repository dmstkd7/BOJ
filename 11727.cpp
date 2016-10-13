#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MOD 10007
using namespace std;

int main(void) {

	int dp[1001], n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]*2) % MOD;
	}
	printf("%d\n", dp[n]);

	return 0;
}
