#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
 
//bfs? dfs? bfs! 
 
char M[25][25];
bool visited[25][25];
int queue[1000];
int counter, N;
 
 
//가로 , 세로 
void bfs(int i, int j){
 
 
    if (i<0 || j<0 || i >= N || j >= N || M[i][j] !='1' || visited[i][j] == true)
        return;
    visited[i][j] = true;
    counter++;
 
    bfs(i, j - 1);
    bfs(i, j + 1);
    bfs(i - 1, j);
    bfs(i + 1, j);
 
}
 
 
int main(void){
 
    int house_ct = 0;
 
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++)
        scanf("%s", &M[i]);
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (M[i][j] == '1' && visited[i][j] == false){
                counter = 0;
                bfs(i, j);
                queue[house_ct++] = counter;
            }
                 
    sort(queue, queue + house_ct);
    printf("%d\n", house_ct);
    for (int i = 0; i < house_ct; i++)
        printf("%d\n", queue[i]);
 
 
 
    return 0;
}
