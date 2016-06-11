#include <cstdio>
#include <memory.h>
#include <queue>
#include <algorithm>
using namespace std;


int map[1001][1001];
bool visited[1001][1001];
int w, h;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue< pair<int,int> > q;

//i, j의 의미는 각각 x좌표 y좌표를 의미한다
void bfs(){
    
    int here_x, here_y, there_x, there_y;

    while(!q.empty()){
        here_x = q.front().first;
        here_y = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++){
            there_x = here_x + dx[i];
            there_y = here_y + dy[i];
            if(there_x >=1 && there_y >=1 && there_x <=w && there_y <=h && map[there_x][there_y] == 0 && visited[there_x][there_y]== false){
                visited[there_x][there_y] = true;
                map[there_x][there_y] = map[here_x][here_y] + 1;
                q.push(make_pair(there_x,there_y));
            }
        }
        
    }
    
    return;
}

int main(void){
    
    int tmp=0;
    bool isIncom = false;
    

    scanf("%d%d", &w,&h);
    
    for(int j=1; j<=h; j++)
        for(int i=1; i<=w; i++){
            scanf("%d", &map[i][j]);
            visited[i][j] = false;
        }
            
            
    
    
    for(int j=1; j<=h; j++)
        for(int i=1; i<=w; i++){
            if(map[i][j] == 1 && visited[i][j] == false){
               q.push(make_pair(i,j));
            }
        }

    bfs();
    
    //프린트하는곳
    for(int j=1; j<=h; j++){
        for(int i=1; i<=w; i++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
       }
        
    
    //확인
    for(int j=1; j<=h; j++)
        for(int i=1; i<=w; i++){
            if(map[i][j]==0)
                isIncom= true;
            tmp = max(tmp, map[i][j]);
        }
            
    
    
    
    if(isIncom)
        printf("-1");
    else
        printf("%d", tmp-1);
        
    return 0;

}
