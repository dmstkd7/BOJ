#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;


int main(void){

	int type, goal,tmp, cnt = 0;
	int coin[11];

	scanf("%d%d", &type, &goal);
	for (int i = 1; i <= type; i++)
		scanf("%d", &coin[i]);
	
	
	while (type !=0 && goal !=0){
		tmp = goal;
		goal %= coin[type];
		if (goal == tmp){
			type--;
			continue;
		}
		cnt += tmp / coin[type];
	}
	printf("%d", cnt);

	return 0;
}
