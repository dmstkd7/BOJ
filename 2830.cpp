#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
typedef unsigned long long ull;
using namespace std;
 
 
int a[1000001], b[21];
 
int main(void) {
 
    int n;
     
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
     
    for (int i = 1; i <= 20; i++) {
        for(int j=1; j<=n; j++)
            b[i] += (a[j] >> i-1) &1;
    }
     
    ull total = 0;
    for (int i = 1; i <= 20; i++) {
        total += (ull)b[i] * (ull)(n - b[i]) * (ull)(1LL << (i-1));
    }
     
    printf("%llu\n", total);
 
 
    return 0;
}
