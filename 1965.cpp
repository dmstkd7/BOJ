#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int a[1002], cache[1002], N;

int lis(int start){

	int& ret = cache[start+1];
	if(ret != -1) return cache[start+1];
	
	ret=1;
	for(int next = start+1; next<N; next++){
		printf("start :%d next : %d  a[start] : %d  a[next] : %d \n ", start, next, a[start], a[next]);
		if(start==-1 || a[start] < a[next])
			ret = max(ret, lis(next)+1);
	//	printf("start : %d ret : %d\n",start, ret);
	}
	

	return cache[start+1] = ret;
}


int main(void){

	int ans;
	scanf("%d", &N);
	for(int i=0; i<=N; i++)
		cache[i] = -1;

	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	
	ans = lis(-1);
	printf("%d\n", ans-1);

	return 0;
}
