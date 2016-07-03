#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct Planet{
	int x, y, z;
	Planet(){}
	Planet(int x, int y, int z) :x(x), y(y), z(z){}
}Planet;


typedef struct DisjointSet{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n,1){
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u){
		if (u == parent[u]) return u;
		return find(parent[u]);
	}

	void merge(int u, int v){
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}

}DisjointSet;

int getDistance(Planet p1, Planet p2){
	return min(abs(p1.x - p2.x), min(abs(p1.y - p2.y), abs(p1.z - p2.z)));
}

const int MAX_P = 100001;
int N;
Planet P[MAX_P];
vector<pair<int, pair<int, int> > > edges;
int pre_temp[600003];

long long kruskal(){
	
	long long ret = 0;
	//vector<int, int> selected;
	//미리미리 소팅을 해놔야겠넹


	for (int i = 1; i <= N; i++){
		for (int j = i + 1; j <= N; j++){
			edges.push_back(make_pair(getDistance(P[i], P[j]), make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());
	
	DisjointSet sets(N + 1);
	for (int i = 0; i < edges.size(); i++){
		int weight = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		if (sets.find(u) == sets.find(v))
			continue;
		sets.merge(u, v);
		//selected.push_back(make_pair(u, v));
		ret += weight;
	}
	return ret;
}


int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].z);
	}	
	printf("%lld\n", kruskal());
	
	return 0;
}



	




