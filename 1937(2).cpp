#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX(a,b) (a>b? (a):(b));
using namespace std;

int N;
int a[501][501];
int dp[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int go(int height, int width){

	if (dp[height][width] != 0) return dp[height][width];
	
	dp[height][width] = 1;
	for (int k = 0; k < 4; k++){
		int nx = width + dx[k];
		int ny = height + dy[k];
		if (nx < 1 || ny < 1 || nx > N || ny >N) continue;
		if (a[height][width] < a[ny][nx])
			dp[height][width] = MAX(dp[height][width], go(ny, nx) + 1);
	}
	return dp[height][width];
}

int main(){

	int ans = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &a[i][j]);
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			ans = MAX(ans, go(i, j));
		}
	}

	printf("%d\n", ans);


		return 0;
}
