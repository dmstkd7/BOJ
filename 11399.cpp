#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

int main(void) {

	int n, p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p);
		a.push_back(p);
	}

	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (n - i) * a[i];
	}
	printf("%d", ans);

	return 0;
}
