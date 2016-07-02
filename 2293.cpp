#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int coin[1001];
int dp[10001];


int main(void){

	int n, k, tmp;
	scanf("%d%d", &n, &k);
	//먼저 입력을 받는다
	for (int i = 1; i <= n; i++){
		scanf("%d", &coin[i]);
	}
	//초기값을 설정해준다
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k ; j++){
			if (j - coin[i] >= 0) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	printf("%d\n", dp[k]);
	

	return 0;
}
