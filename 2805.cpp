#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<long long> tree;
int N;

ll biSearch(ll wantTree) {
	ll ans = 0;
	ll left = 0;
	ll right = 2000000000;

	/*
	for (int i = 0; i<N; i++) {
		if (right < tree[i]) {
			right = tree[i];
		}
	}
	*/

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll getTree = 0;
		for (int i = 0; i < N; i++) {
			if ((tree[i] - mid) > 0)
				getTree += (tree[i] - mid);
		}
		if (getTree < wantTree)
			right = mid - 1;
		else {
			ans = max(ans, mid);
			left = mid + 1;
		}
	}
	return ans;
}

int main(void) {

	ll M;
	ll t;
	scanf("%d %lld", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &t);

		tree.push_back(t);
	}
	
	printf("%lld\n", biSearch(M));
	return 0;
}

