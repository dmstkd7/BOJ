#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
 
int map[101][101];
bool visited[101][101];
vector< pair<int, int> > q[10001];
int counter = 0;
int N;
 
 
 
int getDistance(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d);
}
 
void dfs(int i, int j){
 
    if (i < 1 || j < 1 || i>N || j>N || visited[i][j] == true || map[i][j] != 1)
        return;
 
    visited[i][j] = true;
    q[counter].push_back(make_pair(i, j));
 
    dfs(i, j-1);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i+1, j);
 
    return;
}
 
void getMinimumDistance(){
    //두점 가져다가 비교한다
    int temp = 987654321;
 
    for (int i = 0; i < counter; i++){
        for (int j = i+1; j < counter; j++){
            for (int k = 0; k < q[i].size(); k++){
                for (int l = 0; l < q[j].size(); l++){
 
                    temp = min(temp, getDistance(q[i][k].first, q[i][k].second, q[j][l].first, q[j][l].second));
                }
            }
        }
    }
     
 
    printf("%d", temp-1);
}
 
 
int main(void){
 
 
    scanf("%d", &N);
 
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++){
            scanf("%d", &map[i][j]);
            visited[i][j] = false;
        }
 
 
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++){
            if (visited[i][j] == false && map[i][j] == 1){
                dfs(i, j);
                counter++;
            }
        }
 
 
    getMinimumDistance();
 
    return 0;
 
}
