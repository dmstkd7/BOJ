#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;


int height, width;
int a[501][501];
int dp[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int solve(int y, int x){

	if (dp[y][x] != 0) return dp[y][x];
	if (x == width && y == height) return 1;

	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 1 || ny < 1 || nx > width || ny > height) continue;
		if (a[y][x] > a[ny][nx])
			dp[y][x] += solve(ny, nx);
	}

	return dp[y][x];
}

int main(){
	scanf("%d%d", &height, &width);
	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= width; j++)
			scanf("%d", &a[i][j]);
	solve(1, 1);
	printf("%d\n", dp[1][1]);
	return 0;
}
