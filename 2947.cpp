#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;


int N;
int data[5];

void swap(int *a, int *b){
	int tmp;
	if (*b < *a){
		tmp = *a;
		*a = *b;
		*b = tmp;
		
		for (int i = 0; i < 5; i++)
			printf("%d ", data[i]);
		printf("\n");
	}
}


int main(void){

	int tmp;

	for (int i = 0; i < 5; i++)
		scanf("%d", &data[i]);
	
	//bubble sort
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 4; j++){
			swap(&data[j], &data[j + 1]);
		}
	}
	
	return 0;
}
