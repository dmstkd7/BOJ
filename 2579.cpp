#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

long long dp[301][2];
long long a[301];
int main(void){

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);

	dp[1][0] = dp[1][1] = a[1];

	for (int i = 2; i <= N; i++){
		dp[i][0] = max( dp[i - 2][0] , dp[i-2][1])+ a[i];
		dp[i][1] = dp[i - 1][0] + a[i];
	}
	
	printf("%d", max(dp[N][0],dp[N][1]));
	return 0;
}
