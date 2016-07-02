#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
const int MAX_V = 10001;
const int INF = 987654321;

vector< pair<int, int> > adj[MAX_V];


int prim(){
	int ret = 0;
	vector<bool> added(V+1, false);
	vector< pair<int, int> > selected;
	vector<int> minWeight(V + 1, INF);
	vector<int> parent(V + 1, -1);


	minWeight[1] = parent[1] = 0;
	//prim의 시작은 1
	for (int iter = 1; iter <= V; iter++){
		int here = -1;
		for (int there = 1; there <= V; there++){
			if (!added[there] && (here == -1 || minWeight[here] > minWeight[there]))
				here = there;
		}
		if (parent[here] != here)
			selected.push_back(make_pair(parent[here], here));
		ret += minWeight[here];
		added[here] = true;
		
		for (int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int weight = adj[here][i].second;
			if (!added[there] && minWeight[there] > weight){
				parent[there] = here;
				minWeight[there] = weight;
			}
		}		
	}
	return ret;
}


int main(){
	int v1,v2,w;
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++){
		scanf("%d%d%d", &v1, &v2, &w);
		adj[v1].push_back(make_pair(v2, w));
		adj[v2].push_back(make_pair(v1, w));
	}

	printf("%d", prim());


	return 0;
}
