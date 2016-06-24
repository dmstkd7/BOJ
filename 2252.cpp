#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[32001];
int ind[32001];
queue<int> q;
int N, M;

void topological_sort(){
	
	for (int i = 1; i <= N; i++)
		if (ind[i] == 0)
			q.push(i);

	for (int k = 0; k < N; k++){
		int here = q.front();
		q.pop();
		printf("%d ", here);
		for (int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i];
			ind[there]--;
			if (ind[there] == 0)
				q.push(there);
		}
	}

}


int main(){

	int tmp1,tmp2;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++){
		scanf("%d%d", &tmp1, &tmp2);
		adj[tmp1].push_back(tmp2);
		ind[tmp2]++;
	}

	topological_sort();

	return 0;
}
