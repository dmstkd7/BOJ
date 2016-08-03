#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>
#include <iostream>
typedef unsigned long long ull;

using namespace std;
const ull MOD = 1000000007;

ull g[8][8]=
{
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,0,1},
	{0,0,0,1,1,0,1,0},
	{0,0,0,0,0,1,0,1},
	{0,0,0,0,1,0,1,0}
};

int a[100000];

int main(void) {
	
	int n, t = 0;

	scanf("%d", &n);
	
	while (n>1) {
		a[t] = n;
		if (n % 2 == 1) {
			n--;
		}
		else
			n /= 2;
		t++;
	}

	ull cur[8][8], mulMat[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cur[i][j] = g[i][j];
		}
	}
	while (t-- ) {
		if (a[t] % 2 == 1) {
			memset(mulMat, 0, sizeof(mulMat));
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 8; k++) {
						mulMat[i][j] += g[i][k] * cur[k][j];
					}
				}
			}
		}
		else {
			memset(mulMat, 0, sizeof(mulMat));
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 8; k++) {
						mulMat[i][j] += (cur[i][k]) * (cur[k][j]);
					}
				}
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cur[i][j] = mulMat[i][j] % MOD;
			}
		}
	}


	cout << cur[0][0] << endl;
	return 0;
}
