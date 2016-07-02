#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E;
const int MAX_V = 10001;
const int INF = 987654321;
priority_queue< pair<int, pair<int, int> > > pq;
vector< pair<int, int> > adj[MAX_V];


int prim(){
	int ret = 0;
	vector<bool> added(V + 1, false);
	vector< pair<int, pair<int, int> > > edges;

	//prim의 시작은 1
	added[1] = true;
	for (int i = 0; i < adj[1].size(); i++){
		//pq에 w,v1,v2 순서대로 넣어둔다
		pq.push(make_pair(-adj[1][i].second, make_pair(1, adj[1][i].first)));
	}
	for (int i = 0; i < V -1 ; i++){
		int connect_v, connect_weight;
		while (!pq.empty()){
			connect_v = pq.top().second.second;
			connect_weight = -pq.top().first;
			pq.pop();
			if (added[connect_v] == false)
				break;
		}
		added[connect_v] = true;
		ret += connect_weight;
		int here = connect_v;
		for (int i = 0; i < adj[here].size(); i++){
			int v = adj[here][i].first;
			int weight = adj[here][i].second;
			pq.push(make_pair(-weight, make_pair(here, v)));
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
