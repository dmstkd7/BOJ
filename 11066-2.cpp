#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

int dp[501][501], a[501], sum[501];


int solve(int start, int finish){

	int& ret = dp[start][finish];
	if(ret != -1) return ret;

	if(start == finish)
		return 0;
		

	ret = 987654321;
	for(int i=start; i<finish; i++){
		ret = min(ret, solve(start, i) + solve(i+1, finish) + sum[finish] - sum[start-1]);
	}
	return dp[start][finish] = ret;

}



int main(void){

	int test_case, n, ans;
	scanf("%d", &test_case);
	while(test_case--){
		memset(dp, -1, sizeof(dp));
		memset(a, 0, sizeof(a));
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &a[i]);
			sum[i] += sum[i-1] + a[i];
		}
		ans = solve(1, n);	

		printf("%d\n", ans);
	}

	return 0;
}
