#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool adj[1001][1001];
vector<int> aMatch, bMatch;
vector<bool> visited;
int n, m;

bool dfs(int a) {

	if (visited[a] == true) return false;
	visited[a] = true;

	for (int b = 1; b <= m; b++) {
		if (adj[a][b]) {
			if (bMatch[b] == false || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatch() {
	int cnt = 0;
	
	aMatch = vector<int>(n + 1,0);
	bMatch = vector<int>(m + 1, 0);
	
	for (int start = 1; start <= n; start++) {
		visited = vector<bool>(n + 1, false);
		if (dfs(start))
			cnt++;
		visited = vector<bool>(n + 1, false);
		if (dfs(start))
			cnt++;
	}
	
	return cnt;

}



int main(void) {

	int wn, t;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wn);
		for (int j = 0; j < wn; j++) {
			scanf("%d", &t);
			adj[i][t] = 1;
		}
	}
	printf("%d\n", bipartiteMatch());

	return 0;
}
