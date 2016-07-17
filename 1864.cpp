#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>   
using namespace std;
 
vector<pair< int, int > > adj[2702];
 
 
void bellmanFord(int V){
 
    vector<int> upper(V + 1, 987654321);
 
    upper[1] = 0;
    for (int i = 0; i < V - 1; i++){
        for (int here = 1; here <= V; here++){
            for (int j = 0; j < adj[here].size(); j++){
                int there = adj[here][j].first;
                int cost = adj[here][j].second;
                upper[there] = min(upper[there], upper[here] + cost);
            }
        }
    }
 
    bool isChange = false;
    for (int here = 1; here <= V; here++){
        for (int j = 0; j < adj[here].size(); j++){
            int there = adj[here][j].first;
            int cost = adj[here][j].second;
            if (upper[there] > upper[here] + cost)
                isChange = true;
            }
    }
     
    if (isChange){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return;
}
 
 
int main(void){
 
    int T, v1, v2, w, ans;
    int numOfWorld, numOfRoad, numOfWorm;
 
    scanf("%d", &T);
    while (T--){
        memset(adj, 0, sizeof(adj));
        scanf("%d%d%d", &numOfWorld, &numOfRoad, &numOfWorm);
        for (int i = 0; i < numOfRoad; i++){
            scanf("%d%d%d", &v1, &v2, &w);
            adj[v1].push_back(make_pair(v2, w));
            adj[v2].push_back(make_pair(v1, w));
        }
 
        for (int i = 0; i < numOfWorm; i++){
            scanf("%d%d%d", &v1, &v2, &w);
            adj[v1].push_back(make_pair(v2, -w)); 
        }
        bellmanFord(numOfWorld);
    }
 
 
    return 0;
}
