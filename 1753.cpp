#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
 
typedef pair<int, int> pii;
vector<pii> adj[20001];
 
vector<int> dijkstra(int V, int start){
 
    vector<int> distance(V + 1, INF);
    priority_queue<pii> pq;
    distance[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (distance[here] < cost) continue;
        for (int i = 0; i< adj[here].size(); i++){
            int there = adj[here][i].first;
            int nextDistance = cost + adj[here][i].second;
            if (distance[there] > nextDistance){
                distance[there] = nextDistance;
                pq.push(make_pair(-nextDistance, there));
            }
        }
    }
 
    return distance;
}
 
int main(void){
 
    int V, E, start,v1,v2,w;
    vector<int> ans;
    scanf("%d%d%d", &V, &E, &start);
     
    for (int i = 0; i < E; i++){
        scanf("%d%d%d", &v1, &v2, &w);
        adj[v1].push_back(make_pair(v2, w));
        //adj[v2].push_back(make_pair(v1, w));
    }
 
    ans = dijkstra(V, start);
    for (int i = 1; i <= V; i++){
        if (ans[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", ans[i]);
    }
 
    return 0;
}
