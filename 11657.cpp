#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MIN(a,b) ((a<b)?:a:b);
using namespace std;



const int INF = 987654321;
int N, M;
int city[510];
vector< pair<int, int > > adj[6010];

void bellmanFord() {

	vector<int> saveResult;
	vector<bool> visited(N + 1, false);
	//city의 시작은 0에서 시작
	city[1] = 0;
	queue<int> q;

	for (int iter = 0; iter < N - 1; iter++) {
		q.push(1);
		for (int i = 0; i <= N; i++)
			visited[i] = false;
		while (!q.empty()) {
			int here = q.front();
			visited[here] = true;
			q.pop();
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				city[there] = min(city[there], city[here] + cost);
				if (visited[there] == false)
					q.push(there);
			}
		}
	}
	
	saveResult.push_back(0);
	saveResult.push_back(0);
	for (int i = 2; i <= N; i++) 
		saveResult.push_back(city[i]);

	//만약 여기서 최적화 되는 것이 있다면 중간에 가중치가 음수 인것이 있으므로
	//가장 빠른 시간은 존재 하지 않는다.
	q.push(1);
	for (int i = 0; i <= N; i++)
		visited[i] = false;
	while (!q.empty()) {
		int here = q.front();
		visited[here] = true;
		q.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			city[there] = min(city[there], city[here] + cost);
			if (visited[there] == false)
				q.push(there);
		}
	}

	for (int i = 2; i <= N; i++) 
		if (saveResult[i] > city[i]) {
			printf("-1\n");
			return;
		}
	for (int i = 2; i <= N; i++)
		printf("%d\n", city[i] < INF - 100000 ? city[i] : -1);

	return;
}

int main() {

	int v1, v2, c;
	scanf("%d%d", &N, &M);

	for (int i = 0; i <= N; i++)
		city[i] = INF;

	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &v1, &v2, &c);
		adj[v1].push_back(make_pair(v2, c));
	}

	bellmanFord();

	return 0;
}
