#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int temp[100001];
int dp[100001];
int main(void){

	int N, ans;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &temp[i]);

	dp[1] = temp[1];
	for (int i = 2; i <= N; i++)
		dp[i] = max((dp[i - 1] + temp[i]), dp[i]);

	ans = dp[1];
	for (int i = 1; i <= N; i++)
		if (dp[i] > ans)
			ans = dp[i];

	printf("%d", ans);


	return 0;
}
