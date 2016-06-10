#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
 
int map[52][52];
int a, b;
 
 
//섬의 갯수 구하는거
void sum(int i, int j){
     
    if (i <1 || j<1 || i> b || j >a || map[i][j] == 0)
        return;
     
    map[i][j] = 0;
 
    sum(i-1, j+1);
    sum(i, j+1);
    sum(i+1, j+1);
    sum(i+1, j);
    sum(i+1, j-1);
    sum(i, j-1);
    sum(i-1, j-1);
    sum(i-1, j);
 
 
}
 
int main(void){
 
    int tmp, cnt;
 
    while (1){
 
        scanf("%d%d", &a, &b);
        if (a == 0 || b == 0)
            break;
 
        cnt = 0;
        for (int i = 1; i <= b; i++)
            for (int j = 1; j <= a; j++){
                scanf("%d", &tmp);
                map[i][j] = tmp;
            }
 
        for (int i = 1; i <= b; i++)
            for (int j = 1; j <= a; j++)
                if (map[i][j] == 1){
                    sum(i, j);
                    //printf("%d %d\n", i, j);
                    cnt++;
                }
        printf("%d\n", cnt);
 
    }
 
    return 0;
}
