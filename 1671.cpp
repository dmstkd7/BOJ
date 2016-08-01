#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct shark {
	shark(int s, int v, int iq) : size(s), velo(v), iq(iq) {};
	int size, velo, iq;
}shark;


/*
bool sharkSort(const shark &s1, const shark &s2) {
	return (s1.size <= s2.size) && (s1.velo <= s2.velo) && (s1.iq <= s2.iq);
}
*/

vector<shark> sharks;
int n;
vector<bool> visited;
vector<int> aMatch, bMatch;
//vector<int> aTotal;
bool adj[1001][1001];

bool dfs(int a) {

	if (visited[a] == true) return false;
	visited[a] = true;
	//printf("방문했습니다 %d\n", a);
	for (int i = 1; i <= n; i++) {
		if (adj[a][i]) {
			if(bMatch[i] == false || dfs(bMatch[i])){
				//printf("잡아 먹겠다 %d %d\n", a, i);
				bMatch[i] = a;
				aMatch[a] = i;
				return true;
			}
		}
	}
	return false;
}



int bipartiteMatch() {

	int cnt = 0;
	aMatch = vector<int>(n+1, false);
	bMatch = vector<int>(n+1, false);
	
	for (int start = 1; start <= n; start++) {
		visited = vector<bool>(n+1, 0);
		if (dfs(start))
			cnt++;
		visited = vector<bool>(n + 1, 0);
		if (dfs(start))
			cnt++;
	}
	
	return cnt;
}


int main(void) {
	int a, b, c;
	scanf("%d", &n);
	sharks.push_back(shark(0, 0, 0));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		sharks.push_back(shark(a, b, c));
	}
	
	//sort(sharks.begin()+1, sharks.end(), sharkSort);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (sharks[i].size >= sharks[j].size && sharks[i].velo >= sharks[j].velo && sharks[i].iq >= sharks[j].iq) {
				if (i==j || (i > j && sharks[i].size == sharks[j].size && sharks[i].velo == sharks[j].velo && sharks[i].iq == sharks[j].iq)) {
					continue;
				}	
				adj[i][j] = true;
				//printf("%d %d \n", i, j);
			}
		}
	}

	printf("%d\n", n - bipartiteMatch());


	return 0;
}
