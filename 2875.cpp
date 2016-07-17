#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
int main(void){
 
    int M, N, K, ans = 0;
    scanf("%d%d%d", &N, &M, &K);
    while (1){
        N -= 2;
        M -= 1;
        if (M < 0 || N < 0 || M + N - K < 0)
            break;
        ans++;
    }
    printf("%d", ans);
 
    return 0;
}
