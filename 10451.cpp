//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
 
 
vector<int> adj[1001];
bool visited[1001];
int counter;
 
void dfs(int here){
 
    visited[here] = true;
    for (int i = 0; i < adj[here].size(); i++)
        if (visited[adj[here][i]] == false)
            dfs(adj[here][i]);
    return;
}
 
int main(void){
 
    int Test_Case, N, tmp;
 
    scanf("%d", &Test_Case);
 
    for (int i = 1; i <= Test_Case; i++){
        //초기화
        for (int j = 0; j < 1001; j++)
            adj[j].clear();
        memset(visited, false, sizeof(visited));
        counter = 0;
 
        scanf("%d", &N);
        for (int j = 1; j <= N; j++){
            scanf("%d", &tmp);
            adj[j].push_back(tmp);
            adj[tmp].push_back(j);
        }
 
        for (int i = 1; i <= N; i++){
            if (visited[i] == false){
                dfs(i);
                counter++;
            }
        }
        printf("%d\n", counter);
    }
 
 
 
 
 
    return 0;
}
