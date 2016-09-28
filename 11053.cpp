#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAX ((a>b)? a:b)
using namespace std;

int a[1001];
int cache[1001];
int n;

int solve(int start) {
	
	if (start == n) return 1;
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	int maxValue = a[start];
	for (int i = start+1; i <= n; i++) {
		if (maxValue < a[i]) {
			ret = max(ret, solve(i)+1);
		}
	}
	
	return ret;
}


int main(void) {

	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", solve(0)-1);
	
	return 0;
}
