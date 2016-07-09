#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX(a,b) ((a>b)?a:b);
using namespace std;

const int INF = 987654321;
int N, M, X;
int stduent[1001];
vector< pair<int, int> > adj[1001];


int dijkstra(){
	
	int goX[1001], comeX[1001];
	int ret = 0;
	for (int i = 1; i <= N; i++){
		vector<int> distance(N + 1, INF);
		priority_queue< pair<int, int> > pq;
		int here = i;

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

		if (i != X){
			goX[i] = distance[X];
		}
		else{
			for (int l = 1; l <= N; l++)
				comeX[l] = distance[l];
		}

	}
	for (int e = 1; e <= N; e++){
		if (e == X) continue;
		ret = MAX(ret, goX[e] + comeX[e]);
	}
	return ret;

}



int main(){

	int v1, v2, w;

	scanf("%d%d%d", &N, &M, &X);

	for (int i = 0; i < M; i++){
		scanf("%d%d%d", &v1, &v2, &w);
		adj[v1].push_back(make_pair(v2, w));
	}

	printf("%d\n", dijkstra());

	return 0;
}
