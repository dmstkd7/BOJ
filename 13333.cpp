#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1001];

int main(void) {
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= n - i) {
			ans = n - i;
			break;
		}
	}

	printf("%d\n", ans);

	return 0;
}
