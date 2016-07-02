#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
struct Edge{
    int start;
    int end;
    int weight;
    Edge() :start(0), end(0), weight(0){}
    Edge(int start, int end, int weight) : start(start), end(end), weight(weight){}
    bool operator < (const Edge &ohter) const{
        return weight > ohter.weight;
    }
};
 
 
int V, E;
const int MAX_V = 10001;
const int INF = 987654321;
priority_queue<Edge> pq;
vector< pair<int, int> > adj[MAX_V];
 
 
int prim(){
    int ret = 0;
    vector<bool> added(V + 1, false);
    vector<Edge> edges;
 
    //prim의 시작은 1
    added[1] = true;
    for (int i = 0; i < adj[1].size(); i++){
        //pq에 w,v1,v2 순서대로 넣어둔다
        pq.push(Edge(1, adj[1][i].first, adj[1][i].second));
    }
    for (int i = 0; i < V -1 ; i++){
        Edge e;
        while (!pq.empty()){
            e = pq.top();
            pq.pop();
            if (added[e.end] == false)
                break;
        }
        added[e.end] = true;
        ret += e.weight;
        int here = e.end;
        for (int i = 0; i < adj[here].size(); i++){
            int v = adj[here][i].first;
            int weight = adj[here][i].second;
            pq.push(Edge(here, v, weight));
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
