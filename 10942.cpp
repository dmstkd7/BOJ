#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int value[2001];
int dp[2001][2001];

int main(){

	int N, M, S, E;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &value[i]);

	//먼저 거리가 1,2 인것을 초기화한다
	for (int i = 1; i <= N; i++)
		dp[i][i] = 1;

	for (int i = 1; i + 1 <= N; i++)
		if (value[i] == value[i + 1])
			dp[i][i + 1] = 1;

	//이제 거리가 3 이상인것을 한다
	for (int j = 2; j <= N; j++)
		for (int i = 1; i + j <= N; i++)
			dp[i][i + j] = (dp[i + 1][i + j - 1] && (value[i] == value[i + j]));

	//이제 질문을 한다
	scanf("%d", &M);
	while (M--){
		scanf("%d%d", &S, &E);
		printf("%d\n", dp[S][E]);
	}

	return 0;
}


