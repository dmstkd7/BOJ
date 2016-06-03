#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
 
pair<int, int> adj[236197];
 
int A, P;
 
int getNext(int num){
    int temp, sum = 0;
    int total = 1;
    while (num!=0){
        total = 1;
        temp = num % 10;
        num /= 10;
 
        for (int i = 0; i < P; i++){
            total *= temp;
        }
        sum += total;
    }
    return sum;
}
 
 
int main(void){
 
    int next,count=0,ans;
    scanf("%d%d", &A, &P);
 
    next = A;
    while (1){
        if (adj[next].first != 0)
            break;
        count++;
        next = getNext(A);
        adj[A] = { next, count };
 
        A = next;
    }
 
    printf("%d", adj[next].second-1);
 
    return 0;
}
