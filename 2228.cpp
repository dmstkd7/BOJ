#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
using namespace std;


int a[101];
int cache[101][101];
int sum[101];
int n;
const int INF = 987654321;



int solve(int count, int remain) {

	if (remain == 0) return 0;
	if (count <= 0) return -INF;

	int &ret = cache[count][remain];
	if (ret != -1) return ret;

	//그룹에 속하지 않을때
	ret = solve(count - 1, remain);
	//그룹에 속할 때
	int tmp;
	for (int i = 1; i <= count; i++) {
		tmp = solve(i - 2, remain - 1) + sum[count] - sum[i-1];
		if (ret < tmp)
			ret = tmp;
	}
	
	return ret;
}

int main(void) {

	int m;
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}

	printf("%d", solve(n, m));


	return 0;
}
