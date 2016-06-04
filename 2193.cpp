#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
 
long long D[91];
 
int main(void){
 
    int N;
    scanf("%d", &N);
    D[0] = 0;
    D[1] = 1;
 
    for (int i = 2; i <= N; i++)
        D[i] = D[i - 1] + D[i - 2];
    printf("%lld", D[N]);
 
    return 0;
}
