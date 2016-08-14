#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MOD 1000000000
using namespace std;

int coin[22];
int dp[1000001];

int main(void) {

	int n, t = 1, length = 1;
	scanf("%d", &n);
	for (int i = 1; i/2 <= n; i = i << 1, length++) {
		coin[length] = i;
	}
	
	dp[0] = 1;
	for (int i = 1; i < length; i++) {
		for (int j = 0; j <= n; j++) {
			if (j - coin[i] >= 0)
				dp[j] += dp[j - coin[i]];
			dp[j] %= MOD;
		}
	}
	printf("%d", dp[n]);

	return 0;
}
