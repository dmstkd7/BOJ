#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int a[127][127];

bool isInBoundary(int x, int y, int boundary){
	if (x < 0 || y < 0 || x >= boundary || y >= boundary)
		return false;
	return true;
}


int dijkstra(int V){

	priority_queue< pair<int, pair<int, int > > > pq;
	int distance[125][125];
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			distance[i][j] = INF;
		}
	}
	distance[0][0] = a[0][0];
	pq.push(make_pair(-a[0][0], make_pair(0, 0)));
	while (!pq.empty()){
		int here_x = pq.top().second.second;
		int here_y = pq.top().second.first;
		int cost = -pq.top().first;
		pq.pop();
		if (distance[here_y][here_x] < cost) continue;
		for (int i = 0; i < 4; i++){
			int nx = here_x + dx[i];
			int ny = here_y + dy[i];
			if (!isInBoundary(nx, ny, V)) continue;
			int nextDistance = a[ny][nx] + cost;
			if (distance[ny][nx] > nextDistance){
				distance[ny][nx] = nextDistance;
				pq.push(make_pair(-nextDistance, make_pair(ny, nx)));
			}
		}
	}
	return distance[V-1][V-1];
}


int main(void){

	int N, test_case=1;
	
	while (true){
		scanf("%d", &N);
		if (N == 0) break;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				scanf("%d", &a[i][j]);
			}
		}
		printf("Problem %d: ", test_case++);
		printf("%d\n", dijkstra(N));
	}
	
	return 0;
}
