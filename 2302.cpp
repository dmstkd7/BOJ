#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

long long dp[41];
vector<int> special;

void preCalc(){
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 40; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
}

int main(){
	int N, S, tmp;
	long long ans = 1;
	preCalc();
	scanf("%d%d", &N, &S);
	special.push_back(0);
	for (int i = 0; i < S; i++){
		scanf("%d", &tmp);
		special.push_back(tmp);
	}
	special.push_back(N+1);
	
	for (int i = 1; i < special.size(); i++){
		ans *= (dp[special[i] -special[i - 1]-1]);
	}
	printf("%lld\n", ans);
	return 0;
}
