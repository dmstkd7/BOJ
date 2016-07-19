#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
 
vector< pair<int, int> > adj[100001];
const int INF = 987654321;
 
int dijkstra(int V, int start, int end){
 
    vector<int> distance(V + 1, INF);
    priority_queue< pair<int, int > > pq;
    distance[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (distance[here] < cost) continue;
        for (int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDistance = adj[here][i].second + cost;
            if (nextDistance < distance[there]){
                distance[there] = nextDistance;
                pq.push(make_pair(-nextDistance, there));
            }
        }
    }
 
    return distance[end];
}
 
int main(void){
 
    int V, E, v1, v2, w, start, end;
    scanf("%d%d", &V, &E);
     
    for (int i = 0; i < E; i++){
        scanf("%d%d%d", &v1, &v2, &w);
        adj[v1].push_back(make_pair(v2, w));
    }
    scanf("%d%d", &start, &end);
     
    printf("%d", dijkstra(V, start, end));
 
     
 
    return 0;
}
