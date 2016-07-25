#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

const int MAX_CAGE = 201;
const int MAX_COW = 201;
int N, M;
bool adj[MAX_CAGE][MAX_COW];
vector<int> aMatch, bMatch;
vector<bool> visited;


bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	
	for (int i = 1;  i <= M; i++) {
		if (adj[a][i]) {
			if (bMatch[i] == -1 || dfs(bMatch[i])) {
				aMatch[a] = i;
				bMatch[i] = a;
				return true;
			}
		}
	}
	return false;
}



int bipartiteMatch() {
	int totalMount = 0;

	aMatch = vector<int>(N + 1, -1);
	bMatch = vector<int>(M + 1, -1);

	for (int start = 1; start <= M; start++) {
		visited = vector<bool>(N + 1, false);
		if (dfs(start))
			totalMount++;
	}

	return totalMount;
}


int main(void) {

	int num, t;

	memset(adj, false, sizeof(adj));
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &t);
			adj[i+1][t] = 1;
		}
	}

	printf("%d\n", bipartiteMatch());

	return 0;
}
