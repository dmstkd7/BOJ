#include <cstdio>
#include <iostream>
#include <memory.h>
using namespace std;


int main(void){

	char s[2505];
	bool dp[2501][2501];
	int D[2501];
	memset(dp, false, sizeof(dp));
	scanf("%s", &s[1]);
	
	//get size
	int length=1;
	while(s[length]!=0)
		length++;

	length--;

	//set dp size 1
	for(int i=1; i<=length; i++)
		dp[i][i] = true;

	//set dp size 2
	for(int i=1; i<length; i++)
		if(s[i]==s[i+1])
			dp[i][i+1] = true;

	for(int step = 2; step < length; step++){
		for(int i=1; i + step <= length; i++){
			if(dp[i+1][i+step -1] == true && s[i]==s[i+step])
				dp[i][i+step] = true;
		}
	}
	
	//find min cnt value
	int ans=0;
	D[0] = 0;

	for(int i=1; i<=length; i++){
		D[i] = -1;
		for(int j=1; j<=i; j++){
			if(dp[j][i]){
				if(D[i]==-1 || D[i] > D[j-1] + 1)
					D[i] = D[j-1] + 1;
			}
		}
	}

	printf("%d\n", D[length]);



	return 0;
}
