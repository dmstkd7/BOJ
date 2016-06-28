#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
 
int N;
int build_time[501];
int saved_time[501];
vector<int> adj[501];
queue<int> q;
int ind[501];
 
 
void solve(){
 
    for (int i = 1; i <= N; i++)
        if (ind[i] == 0){
            q.push(i);
            saved_time[i] = build_time[i];
        }
             
 
    while (!q.empty()){
        int here = q.front();
        q.pop();
        for (int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            ind[there]--;
            saved_time[there] = max(saved_time[here] + build_time[there], saved_time[there]);
            if (ind[there] == 0)
                q.push(there);
        }
    }
 
    for (int i = 1; i <= N; i++){
        printf("%d\n", saved_time[i]);
    }
    return;
}
 
int main(){
 
    int tmp;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        tmp = 1;
        scanf("%d", &build_time[i]);
        while (tmp != -1){
            scanf("%d", &tmp);
            if (tmp == -1) break;
            adj[tmp].push_back(i);
            ind[i]++;
        }
    }
 
    solve();
 
    return 0;
}
