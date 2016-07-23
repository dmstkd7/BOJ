#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
 
 
vector<int> adj[101];
vector<bool> visited(101, false);
 
void dfs(int cur) {
 
 
    visited[cur] = 1;
     
    for (int i = 0; i < adj[cur].size(); i++) {
        int there = adj[cur][i];
        if (visited[there] == false)
            dfs(there);
    }
 
}
 
int main() {
 
    int N,E, v1, v2, ans = 0;
    scanf("%d%d", &N, &E);
 
    for (int i = 0; i < E; i++) {
        scanf("%d%d", &v1, &v2);
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    dfs(1);
    for (int i = 2; i <= N; i++) {
        if (visited[i] == true)
            ans++;
    }
     
    printf("%d", ans);
 
 
    return 0;
}
