#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MIN(a,b) ((a<b)?a:b);
using namespace std;
 
//dp[i][j] = i, j 까지 곱했을때 최소값이다
int a[510];
int dp[510][510];
const int INF = 987654321;
 
int main(void){
 
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &a[i], &a[i+1]);
    }
     
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
     
    //step 1인건 다 구했다
    for (int i = 1; i < n; i++)
        dp[i][i + 1] = a[i] * a[i + 1]*a[i+2];
 
    //이제 n인거 계산하자
    for (int step = 2; step < n; step++){
        for (int i = 1; i + step <= n; i++){
            for (int k = i; k < i + step; k++){
                dp[i][i + step] = MIN(dp[i][i + step], dp[i][k] + dp[k+1][i+step] + a[i]*a[k+1]* a[i + step+1]);
            }
        }
    }
      
    //이제 최소값을 구해보자
    printf("%d\n", dp[1][n]);
 
 
    return 0;
}
