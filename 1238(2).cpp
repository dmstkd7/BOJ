#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX(a,b) ((a>b)?a:b);
using namespace std;

const int INF = 987654321;
int N, M, X;
vector< pair<int, int> > vec[1001];
vector< pair<int, int> > vec2[1001];


vector<int> dijkstra(vector< pair<int, int> >* adj){
	
	int ret = 0;

	vector<int> distance(N + 1, INF);
	priority_queue< pair<int, int> > pq;
	int here = X;

	distance[here] = 0;
	for (int j = 0; j < adj[here].size(); j++){
		int there = adj[here][j].first;
		int weight = adj[here][j].second;
		distance[there] = weight;
		pq.push(make_pair(-weight, there));
	}

	while (!pq.empty()){
		int here = pq.top().second;
		int weight = - pq.top().first;
		pq.pop();
			
		if (distance[here] < weight) continue;
			
		for (int k = 0; k < adj[here].size(); k++){
			int there = adj[here][k].first;
			int nextWeight = distance[here] + adj[here][k].second;
			if (distance[there] > nextWeight){
				distance[there] = nextWeight;
				pq.push(make_pair(-nextWeight, there));
			}
		}
	}

	return distance;

}



int main(){

	int v1, v2, w, ans = 0;
	vector<int> goX;
	vector<int> comeX;

	scanf("%d%d%d", &N, &M, &X);

	for (int i = 0; i < M; i++){
		scanf("%d%d%d", &v1, &v2, &w);
		vec[v1].push_back(make_pair(v2, w));
		vec2[v2].push_back(make_pair(v1, w));
	}
	goX = dijkstra(vec);
	comeX = dijkstra(vec2);
	for (int i = 1; i <= N; i++){
		ans = MAX(ans, goX[i] + comeX[i]);
	}

	printf("%d\n", ans);

	return 0;
}
