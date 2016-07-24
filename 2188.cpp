#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#define MIN(a,b) ((a<b)?a:b)
using namespace std;

const int MAX_COW = 200;
const int MAX_CAGE = 200;
const int INF = 987654321;
vector<int> adj[MAX_COW + MAX_CAGE + 2 ];
int N, M;

int capacity[410][410];
int flow[410][410];


int MCMF(int source, int sink) {

	int totalFlow = 0;
	while (1) {
		int amount = INF;
		queue<int> q;
		vector<int> parent(N + M + 3, -1);
		parent[source] = 0;
		q.push(source);
		while (!q.empty() && parent[sink] == -1) {
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i];
				//먼가 더 해야 할거 같은데 잘 모르겠다
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					parent[there] = here;
					q.push(there);
				}
			}
		}
		if (parent[sink] == -1)
			break;
		
		for (int p = sink; p != source; p = parent[p]) {
			amount = MIN(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
		}
		
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}


int main() {

	int t, wantPlace;
	scanf("%d%d", &N, &M);

	for (int i = 0; i <N; i++) {
		adj[0].push_back(i+2);
		adj[i + 2].push_back(0);
		capacity[0][i+2] = 1;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		for (int j = 0; j < t; j++) {
			scanf("%d", &wantPlace);
			adj[i+2].push_back(wantPlace+ N +1);
			adj[wantPlace + N + 1].push_back(i + 2);
			capacity[i + 2][wantPlace + N + 1] = 1;
		}
	}
	
	for (int i = 0; i < M; i++) {
		adj[N + 2 + i].push_back(1);
		adj[1].push_back(N + 2 + i);
		capacity[N + 2 + i][1] = 1;
	}
	

	

	printf("%d\n", MCMF(0, 1));

	return 0;
}
