#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

int city;
int map[17][17];
int cache[17][1<<17];

int solve(int current, int visited) {
	
	if (visited == ((1 << (city+1)) - 1)) {
		return map[current][1];
	}
	int& ret = cache[current][visited];
	if (ret >=0 ) return ret;
	
	ret = 987654321;
	for (int next = 1; next <= city; next++) {
		if (visited & (1 << (next - 1))) {
			continue;
		}
		if (map[current][next] == 0) continue;
		int cand = map[current][next] + solve(next, visited + (1 << (next - 1)));
		//printf("%d %d \n", map[current][next], solve(next, visited + (1<< (next-1))));
		ret = min(ret, cand);
	}

	return ret;
	
}



int main(void) {


	memset(cache, -1, sizeof(cache));
	scanf("%d", &city);
	
	for (int i = 1; i <= city; i++) {
		for (int j = 1; j <= city; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int ans = solve(1, (1 << city) +1);

	printf("%d\n", ans);


	return 0;
}
