#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define num 1000000000
using namespace std;
 
 
int D[101][10];
 
int main(void){
 
    int N = 0;
    long long ans = 0;
    scanf("%d", &N);
 
    for (int i = 1; i <= 9; i++)
        D[1][i] = 1;
 
    for (int i = 2; i <= N; i++){
        D[i][0] = D[i - 1][1] % num;
        D[i][1] = (D[i - 1][0] + D[i - 1][2]) % num;
        D[i][2] = (D[i - 1][1] + D[i - 1][3]) % num;
        D[i][3] = (D[i - 1][2] + D[i - 1][4]) % num;
        D[i][4] = (D[i - 1][3] + D[i - 1][5]) % num;
        D[i][5] = (D[i - 1][4] + D[i - 1][6]) % num;
        D[i][6] = (D[i - 1][5] + D[i - 1][7]) % num;
        D[i][7] = (D[i - 1][6] + D[i - 1][8]) % num;
        D[i][8] = (D[i - 1][7] + D[i - 1][9]) % num;
        D[i][9] = D[i - 1][8] % num;
    }
     
    for (int i = 0; i <= 9; i++)
        ans += D[N][i];
    ans %= num;
    printf("%d", ans);
 
 
    return 0;
}
