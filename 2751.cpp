#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

void quicksort(vector<int>& num, int left, int right){

	int tmp, pivot_pos;
	int pivot = num[left];
	int left_hold = left, right_hold = right;

	while (left < right){
		//끝에서 부터 pivot보다 작은 것을 찾는다
		while ((pivot <= num[right]) && left < right)
			right--;

		if (left < right)
			num[left++] = num[right];
		
		//왼쪽끝에서부터 pivot보다 큰 것을 찾는다
		while ((pivot >= num[left]) && left < right)
			left++;

		if (left < right)
			num[right--] = num[left];
	}
	num[left] = pivot;

	pivot_pos = left;

	if (pivot_pos-1 > left_hold)
		quicksort(num, left_hold, pivot_pos - 1);
	if (pivot_pos+1 < right_hold)
		quicksort(num, pivot_pos + 1, right_hold);

}

int main(void){

	int tmp, N;
	vector<int> data;

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &tmp);
		data.push_back(tmp);
	}

	quicksort(data, 0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d\n", data[i]);

	return 0;
}
