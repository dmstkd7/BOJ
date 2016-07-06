#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
 
 
int main(){
    long long int N, L;
    scanf("%lld%lld", &N, &L);
    long long int sum, ans = 0;
 
    if (N - ((L - 1)*(L) / 2) == 0){
        for (int i = 0; i < L; i++)
            printf("%d ", i);
        return 0;
    }
 
    for (long long int i = L; i <= 100; i++){
        sum = (i*(i + 1)) / 2;
        if (N < sum) break;
        if (((N - sum) % i) == 0){
            ans = (N - sum) / i;
            for (long long int j = 1; j <= i; j++)
                printf("%lld ", ans + j);
            ans = 987654321;
            break;
        }
    }
    if (ans == 0)
        printf("%d", -1);
     
    return 0;
}
