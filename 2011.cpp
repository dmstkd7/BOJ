#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

char N[5001];
int dp[5001];
int main(void){

	int before, current;

	scanf("%s", &N);

	dp[0] = 1;

	int i = 1;
	while (N[i-1] != NULL){
		current = N[i-1] - '0';
		if (current >= 1 && current <= 9)
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;


		if (i == 1){
			i++;
			continue;

		}

		before = N[i - 2] - '0';
		if (before == 0){
			i++;
			continue;
		}

		if (before == 1 || (before == 2 && current <= 6))
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;

		i++;
	}

	printf("%d", dp[i - 1]);


	return 0;

}
