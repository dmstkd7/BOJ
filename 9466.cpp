#include <cstdio>
using namespace std;
 
int student[100001];
int visited[100001];
int count[100001];
 
 
 
int dfs(int here, int ct, int &step){
     
   while (true) {
        if (visited[here] != 0) {
            if (step != count[here]) {
                return 0;
            }
            return ct-visited[here];
        }
        visited[here] = ct;
        count[here] = step;
        here = student[here];
        ct += 1;
    }
}
 
 
int main(void){
     
    int T, N, counter=0;
    int ret;
     
    scanf("%d", &T);
    for(int i = 1; i<=T; i++){
 
        ret = 0;
        scanf("%d", &N);
        for(int i=1; i<=N; i++){
            scanf("%d", &student[i]);
            visited[i]=0;
            count[i] = 0;
        }
             
         
        for(int i=1; i<=N; i++){
 
            if(visited[i] == 0)
                ret += dfs(i, 1, i);    
        }
             
         
        printf("%d\n", N-ret);
         
         
    }
     
    return 0;
}
