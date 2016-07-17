#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
 
int main(void){
 
    int i = 0, sum = 0, ans = 0;
    string N;
    cin >> N;
 
    while (N[i]!=0){
        sum += N[i]-'0';
        i++;
    }
    sort(N.begin(), N.end());
 
    if (N[0] == '0' && sum % 3 == 0){
        reverse(N.begin(), N.end());
        cout << N << endl;
    }
    else
        cout << "-1" << endl;
 
    return 0;
}
