#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int a[1001], sum[1001];
int cache[1001][1001];
 
int go(int front, int rear) {
 
    if (front > rear) return 0;
    if (front == rear) return a[front];
    int& ret = cache[front][rear];
    if (ret != -987654321) return ret;
    ret = max(sum[rear] - sum[front - 1] - go(front + 1, rear), sum[rear] - sum[front - 1] - go(front, rear - 1));
    return ret;
}
 
 
int main(void) {
 
    int test_case, n;
    scanf("%d", &test_case);
    for (int i = 0; i < test_case; i++) {
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j]);
            sum[j] = sum[j - 1] + a[j];
        }
        for (int j = 1; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                cache[j][k] = -987654321;
            }
        }
        printf("%d\n", go(1, n));
    }
 
//  printf("dd");
    return 0;
}
