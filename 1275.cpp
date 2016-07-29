#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

typedef struct FenwickTree {
	vector<long long> tree;
	FenwickTree(int n) : tree(n + 1) {}

	long long sum(int pos) {
		long long ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void add(int pos, long long val) {
		while (pos < (int)tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
}FenwickTree;

int main(void) {
	int n, m, tmp, a, b, c, d;
	scanf("%d%d", &n, &m);

	FenwickTree ft(n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		ft.add(i, tmp);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a > b) {
			tmp = b;
			b = a;
			a = tmp;
		}

		printf("%lld\n", ft.sum(b) - ft.sum(a - 1));
		long long currentNum = ft.sum(c) - ft.sum(c - 1);
		ft.add(c, d-currentNum);
	}


	return 0;
}
