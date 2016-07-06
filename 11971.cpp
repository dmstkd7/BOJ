#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX(a,b) ( (a>b)? (a): (b) );
using namespace std;
 
int N, M;
int road[101];
int bassie[101];
 
int main(){
 
    int t1,t2;
 
    scanf("%d%d", &N, &M);
     
     
    int road_length = 1;
    while(road_length!=101){
        scanf("%d%d", &t1, &t2);
        int i = 0;
        for (; i < t1; i++)
            road[i+road_length] = t2;
        road_length += i;
    }
     
    int bassie_length = 1;
    while (bassie_length != 101){
        scanf("%d%d", &t1, &t2);
        int i = 0;
        for (; i < t1; i++)
            bassie[i+bassie_length] = t2;
        bassie_length += i;
    }
     
    int ans = 0;
    for (int i = 1; i <= 100; i++){
        if (bassie[i] - road[i])
            ans = MAX(ans, (bassie[i] - road[i]));
    }
 
    printf("%d\n", ans);
 
    return 0;
}
