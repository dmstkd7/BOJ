#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX(a,b) ((a>b)?a:b)
using namespace std;
 
int N, M;
int miro[1001][1001]; //순서 x,y 순서로 하겠다
int dp[1001][1001];
 
int main(){
 
    int tmp;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++){
            scanf("%d", &tmp);
            miro[j][i] = tmp;
        }
 
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++){
            dp[j][i] = MAX(dp[j - 1][i - 1], MAX(dp[j - 1][i], dp[j][i - 1])) + miro[j][i];
        }
 
    printf("%d", dp[M][N]);
 
 
    return 0;
}
