#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int a[10001];
int dp[10001];


int main(void) {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	//dp[i]는 i를 먹을 때 최대가 되는 것을 골라라
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	dp[3] = a[3] + max(a[1], a[2]);
	dp[3] = max(dp[3], dp[2]);
	for (int i = 4; i <= n; i++) {
		dp[i] = a[i] + max(dp[i - 2], a[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	printf("%d\n", dp[n]);

	return 0;
}
