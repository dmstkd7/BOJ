#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
 
int D[100001][2];
int A[100001][3];
 
int main(void){
 
    int T, N, ans;
 
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        ans = 0;
        scanf("%d", &N);
        for (int j = 0; j < 2; j++)
            for (int i = 1; i <= N; i++){
                scanf("%d", &D[i][j]);
            }
         
        A[1][0] = 0;
        A[1][1] = 0;
        A[1][2] = 0;
 
        for (int i = 1; i <= N; i++){
            A[i][0] = max(A[i - 1][1], A[i - 1][2]) + D[i][0];
            A[i][1] = max(A[i - 1][0], A[i - 1][2]) + D[i][1];
            A[i][2] = max(max(A[i - 1][0], A[i - 1][1]), A[i - 1][2]);
        }
 
        for (int i = 1; i <= N; i++)
            ans = max(max(max(ans, A[i][0]), A[i][1]), A[i][2]);
 
        printf("%d\n", ans);
 
    }
 
 
 
    return 0;
}
