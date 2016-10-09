#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
using namespace std;

int boong[1001];
int cache[1001];
int n;

int go(int count) {

	int tmp;
	//기저 사례
	if (count == 0) return 0;
	int& ret = cache[count];
	if (ret != -1) return ret;
	
	ret = -1;
	for (int i = 0; i < count; i++) {
		tmp = go(i) + boong[count - i];
		if (ret < tmp)
			ret = tmp;
	}

	return ret;
}


int main(void) {

	
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= n; i++) {
		scanf("%d", boong + i);
	}
	printf("%d\n", go(n));

	return 0;
}
