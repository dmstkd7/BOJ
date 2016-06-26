#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;

int N;
int work[10001];
int ind[10001];
int work_saved[10001];
vector<int> adj[10001];
queue<int> q;

void topological_sort(){
	
	int tmp = 0;
	for (int i = 1; i <= N; i++)
		if (ind[i] == 0){
			q.push(i);
			work_saved[i] = work[i];
		}

	while(!q.empty()){
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i];
			work_saved[there] = MAX(work_saved[there], work_saved[here] + work[there]);
			ind[there]--;
			if (ind[there] == 0)
				q.push(there);
		}
	}

	for (int i = 1; i <= N; i++)
		tmp = MAX(tmp, work_saved[i]);
	printf("%d", tmp);
}


int main(){

	int hour, num, tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &hour);
		work[i] = hour;
		scanf("%d", &num);
		ind[i] = num;
		while (num--){
			scanf("%d", &tmp);
			adj[tmp].push_back(i);
		}
	}

	topological_sort();

	return 0;
}
