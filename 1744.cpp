#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	const int INF = 987654321;
	vector<int> a;
	vector<int> b;
	int n,t;
	bool hasZero = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t > 0)
			a.push_back(t);
		else if (t < 0)
			b.push_back(t);
		else
			hasZero = true;
	}
	a.push_back(-INF);
	b.push_back(INF);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int total = 0;
	for (int i = 0; i < a.size()-1; i++) {
		if (a[i] == 1 && a[i + 1] == 1) {
			total += 2;
			i++; 
		}
		else if(a[i+1] == -INF){
			total += a[i];
			break;
		}
		else if (a[i + 1] == 1) {
			total += a[i];
		}
		else {
			total += a[i + 1] * a[i];
			i++;
		}
	}

	for (int i = 0; i < b.size()-1; i++) {
		if (b[i + 1] == INF) {
			if (hasZero)
				break;
			total += b[i];
		}
		else {
			total += b[i] * b[i + 1];
			i++;
		}

	}

	printf("%d\n", total);
	return 0;
}
