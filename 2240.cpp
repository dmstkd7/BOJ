#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;


int a[1001];
int cache[1001][31][3];


int go(int time, int turn, int current) {
	
	if (time == 0 && current==1) return 0;
	if (time == 0 && current == 2) return -987654321;
	int& ret = cache[time][turn][current];
	if (ret != -1) return ret;
	
	int plus = 0;
	if (current == a[time]) plus = 1;

	ret = go(time - 1, turn, current) + plus;
	if (turn != 0) {
		ret = max(ret, go(time - 1, turn - 1, 3 - current) + plus);
	}

	return ret;
}


int main(void) {
	
	int n, m;
	scanf("%d%d", &n, &m);
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	printf("%d\n", max(go(n, m, 1), go(n,m,2)));


	return 0;
}
