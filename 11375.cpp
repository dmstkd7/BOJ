#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
const int MAX_V = 1001;
bool adj[MAX_V][MAX_V];
vector<int> aMatch, bMatch;
vector<bool> visited;


bool dfs(int a) {

	if (visited[a]) return false;
	visited[a] = true;
	
	for (int b = 1; b <= M; b++) {
		if (adj[a][b]) {
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}


int bipartiteMatch() {

	int total = 0;
	aMatch = vector<int>(N + 1, -1);
	bMatch = vector<int>(M + 1, -1);
	
	for (int start = 1; start <= N; start++) {
		visited = vector<bool>(N + 1, false);
		if (dfs(start))
			total++;
	}

	return total;
}

int main(void) {

	int num, t;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &t);
			adj[i+1][t] = true;
		}
	}
	printf("%d\n", bipartiteMatch());

	return 0;
}
