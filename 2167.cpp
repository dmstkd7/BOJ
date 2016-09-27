#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
using namespace std;


int sum[301][301];
int a[301];

int main(void) {
	
	int h, w, tmp;
	scanf("%d%d", &h, &w);
	//sum[i][j] = 1,1 부터 i, j의 합을 의미합니다
	for (int i = 1; i <= h; i++) {
		memset(a, 0, sizeof(a));
		for (int j = 1; j <= w; j++) {
			scanf("%d", &tmp);
			a[j] = a[j-1] + tmp;
			sum[i][j] = sum[i - 1][j] + a[j];
		}
	}

	int k, a, b, c, d;
	for (scanf("%d", &k); k--; ) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1]);
	}
	

	return 0;
}
