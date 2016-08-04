#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
//#define MIN(a,b) ((a<b)?a:b);
using namespace std;

char s[51][51];


int check(int h_start, int w_start, char check) {
	char criteria = check;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2) {
				if (j % 2) {
					if (s[h_start + i][w_start + j] != criteria)
						cnt++;
				}
				else {
					if (s[h_start + i][w_start + j] == criteria)
						cnt++;
				}
			}
			else {
				if (j % 2) {
					if (s[h_start + i][w_start + j] == criteria)
						cnt++;
				}
				else {
					if (s[h_start + i][w_start + j] != criteria)
						cnt++;
				}
			}
		}
	}	
	return cnt;
}


int main(void) {

	int m, n;
	int ans = 987654321;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
		scanf("%s", &s[i]);

	for (int i = 0; i + 7 < m; i++) {
		for (int j = 0; j + 7 < n; j++) {
			ans = min(ans, check(i, j, 'W'));
			ans = min(ans, check(i, j, 'B'));
			//printf("%d\n", ans);
		}
	}

	printf("%d", ans);
	return 0;
}
