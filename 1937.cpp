#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define MAX(a,b) (a>b? (a):(b));
using namespace std;

int N;
int a[501][501];
int dp[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

priority_queue< pair< int, pair<int, int> > > pq;

int main(){

	int ans = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			scanf("%d", &a[i][j]);
			pq.push(make_pair(a[i][j], make_pair(i, j)));
		}
	
	while(!pq.empty()){
		int height = pq.top().second.first;
		int width = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		int maxValue = 0;
		dp[height][width] = 1;
		for (int j = 0; j < 4; j++){
			int nx = width + dx[j];
			int ny = height + dy[j];
			if (a[height][width] < a[ny][nx])
				maxValue = MAX(maxValue, dp[ny][nx] + 1);
		}
		if (maxValue!=0)
			dp[height][width] = maxValue;
		if (ans < dp[height][width])
			ans = dp[height][width];
	}
	printf("%d\n", ans);


	return 0;
}
