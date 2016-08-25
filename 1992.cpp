#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;


const int MAX_V = 67;
string m1[MAX_V][MAX_V];
string m[MAX_V];


string solve(int x, int y, int size) {
	
	if (size == 1) {
		//cout << y << x << m1[y][x] << endl;
		return m1[y][x];
	}

	string a, b, c, d;
	string ret = "";
	
	a = solve(x, y, size / 2);
	b = solve(x + size / 2, y, size / 2);
	c = solve(x, y + size / 2, size / 2);
	d = solve(x + size / 2, y + size / 2, size / 2);

	if (a=="1" && b=="1" && c== "1" && d== "1") ret = a;
	else if (a == "0" && b == "0" && c == "0" && d == "0") ret = a;
	else {
		ret = "(" + a + b + c + d + ")";
	}

	return ret;
}



int main(void) {

	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m[i];
		for (int j = 0; j < n; j++) {
			m1[i][j] = m[i][j];
		}
	}
	
	cout << solve(0, 0, n) << '\n';


	return 0;
}
