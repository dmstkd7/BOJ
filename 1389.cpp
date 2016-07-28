#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
#define MIN(a,b) ((a<b)?a:b);

int user[101][101];
int N, M;

int floyd() {

	int sum[101];
	memset(sum, 0, sizeof(sum));
	
	for (int i = 1; i <= N; i++) {
		user[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (user[i][k] && user[k][j])
					user[i][j] = MIN(user[i][j], user[i][k] + user[k][j]);
			}
		}
	}

	int min = 987654321;
	int index = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			sum[i] += user[i][j];
		}
		if (min > sum[i]) {
			min = sum[i];
			index = i;
		}
		min = MIN(min, sum[i]);
	}
	
	return index;
}


int main(void){
	int a, b;
	scanf("%d%d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			user[i][j] = 987654321;
		}
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &a, &b);
		user[a][b] = 1;
		user[b][a] = 1;
	}
	printf("%d\n", floyd());

	return 0;
}
