#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
const int MAX_PEOPLE = 400;
const int MAX_JOB = 400;
const int MAX_V = 810;
const int INF = 987654321;
 
int flow[MAX_V][MAX_V], capacity[MAX_V][MAX_V], cost[MAX_V][MAX_V];
vector<int> connection[MAX_V];
vector<int> dist;
vector<bool> visited;
vector<int> parent;
int N, M;
 
void addEdge(int start, int end, int c) {
    if (!flow[start][end] && !flow[end][start]) {
        connection[start].push_back(end);
        connection[end].push_back(start);
    }
    flow[start][end]++;
    cost[start][end] = c;
    cost[end][start] = -c;
}
 
 
int spfa() {
     
    visited = vector<bool>(N + M + 2, false);
    parent = vector<int>(N + M + 2, -1);
    dist = vector<int>(N + M + 2, -INF);
 
    dist[0] = 0;
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        visited[here] = 0;
        for (int i = 0; i < connection[here].size(); i++) {
            int there = connection[here][i];
            //이건 왜 하는건지 아직 잘 모르겠다
            if (!flow[here][there]) continue;
            if (dist[there] < dist[here] + cost[here][there]) {
                dist[there] = dist[here] + cost[here][there];
                parent[there] = here;
                if (!visited[there]) {
                    visited[there] = true;
                    q.push(there);
                }
            }
        }
    }
    return dist[M + N + 1] > -INF;
}
 
 
int main(void) {
 
    int num, numOfWork, numOfCost;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            scanf("%d%d", &numOfWork, &numOfCost);
            addEdge(i, N+numOfWork, numOfCost);
        }
    }
 
    for (int i = 1; i <= N; i++)
        addEdge(0, i, 0);
    for (int i = 1; i <= M; i++)
        addEdge(N+i, M + N + 1, 0);
 
    int cnt = 0;
    int totalFlow = 0;
    while (spfa()) {
        cnt++;
        totalFlow += dist[M + N + 1];
        //printf("%d\n", dist[M + N + 1]);
        for (int p = N + M + 1; p !=0 ; p = parent[p]) {
            flow[parent[p]][p]--;
            flow[p][parent[p]]++;
        }
    }
    printf("%d\n%d\n", cnt, totalFlow);
 
    return 0;
}
