#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int N;
int map[101][101];		//순서를 y,x로 하자 
long long dp[101][101];
void search(int y, int x){
	
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			int here = map[i][j];
			if (i == N && j == N)
				break;
			if (dp[i][j] > 0){
				if (here + i <= N)
					dp[here + i][j] += dp[i][j];
				if (here + j <= N)
					dp[i][here + j] += dp[i][j];
			}
		}
	return;
}

int main(){

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	
	search(1,1);
		
	printf("%lld", dp[N][N]);
	return 0;
}
