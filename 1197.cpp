#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct DisjointSet{
	vector<int> parent;
	DisjointSet(int n) : parent(n+1) {
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
	
	int find(int u) const{
		if (u == parent[u]) return u;
		return find(parent[u]);
	}

	void merge(int u, int v){
		u = find(u);
		v = find(v);
		if (u == v) return;
		parent[u] = v;
	}
}disjointSet;

const int MAX_V = 10001;
int V, E;
// v2, w 순서를 담는다
vector < pair<int, int> > adj[MAX_V];


int kruskal(){
	int ret = 0;
	vector< pair<int, int> > selected;
	vector< pair<int, pair<int, int> > > edges;
	for (int here = 0; here < V; here++){
		for (int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			edges.push_back(make_pair(cost, make_pair(here, there)));
		}
	}
	
	//엉망진창인거 sort해서 cost가 앞인걸로 순서를 바꿔둔다
	sort(edges.begin(), edges.end());
	DisjointSet sets(V);
	for (int i = 0; i < edges.size(); i++){
		int cost = edges[i].first;
		int here = edges[i].second.first;
		int there = edges[i].second.second;
		//싸이클 체크
		if (sets.find(here) == sets.find(there)) continue;
		//아니면 합친다
		sets.merge(here, there);
		selected.push_back(make_pair(here, there));
		ret += cost;
	}
	return ret;
}


int main(void){

	int v1,v2,w;
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++){
		scanf("%d%d%d", &v1, &v2, &w);
		adj[v1].push_back(make_pair(v2, w));
		adj[v2].push_back(make_pair(v1, w));
	}

	printf("%d", kruskal());


	return 0;
}
