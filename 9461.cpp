#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main(void) {

	//전처리
	long long int a[101];
	int n, test_case;
	a[1] = a[2] = a[3] =1;
	a[4] = a[5] = 2;
	for (int i = 6; i <= 100; i++) {
		a[i] = a[i - 1] + a[i - 5];
	}
	
	for (scanf("%d", &test_case); test_case--;) {
		scanf("%d", &n);
		printf("%lld\n", a[n]);
	}
	
	return 0;
}
