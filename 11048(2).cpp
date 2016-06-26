#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

int N, M;
int dp[1001];

int main(){

	int tmp;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++){
			scanf("%d", &tmp);
			dp[j] = MAX(dp[j - 1], dp[j]) + tmp;
		}
	printf("%d", dp[M]);
	return 0;
}
