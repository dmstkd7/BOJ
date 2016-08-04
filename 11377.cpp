#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
 
const int MAX_PEOPLE = 1010;
const int MAX_JOB = 1010;
vector<int> adj[MAX_PEOPLE];
int N, M, K;
vector<int> aMatch, bMatch;
vector<bool> visited;
 
bool dfs(int a) {
 
    if (visited[a] == true) return false;
    visited[a] = true;
 
    for (int i = 0; i < adj[a].size(); i++) {
        int there = adj[a][i];
        if (bMatch[there] == false || dfs(bMatch[there])) {
            bMatch[there] = a;
            aMatch[a] = there;
            return true;
        }
    }
    return false;
}
 
 
int bipartiteMatch() {
    aMatch = vector<int>(N + 1, false);
    bMatch = vector<int>(M + 1, false);
    int cnt = 0;
 
 
    for (int start = 1; start <= N; start++) {
        visited = vector<bool>(N + 1, false);
        if (dfs(start))
            cnt++;
    }
 
 
    int k = 0;
    for (int start = 1; start <= N; start++) {
        if (cnt == M) break;
        if (k == K) break;
        visited = vector<bool>(N + 1, false);
        if (dfs(start)) {
            cnt++;
            k++;
        }
    }
 
    return cnt;
}
 
int main(void) {
 
    int num, t;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &t);
            adj[i].push_back(t);
        }
    }
 
    printf("%d\n", bipartiteMatch());
 
 
    return 0;
}
