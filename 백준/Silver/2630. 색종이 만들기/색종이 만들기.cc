#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int result[2] = { 0 };

void check_paper(int** arr, int size, int startX, int startY);

int main(void) {
	int paper_size = 0; cin >> paper_size;
	int** arr = new int* [paper_size];
	for (int i = 0; i < paper_size; i++) arr[i] = new int[paper_size];
	
	for (int i = 0; i < paper_size; i++) {
		for (int j = 0; j < paper_size; j++) {
			cin >> arr[i][j];
		}
	}

	check_paper(arr, paper_size, 0, 0);

	for (int i = 0; i < 2; i++) {
		cout << result[i] << endl;
	}
}

void check_paper(int** arr, int size, int startX, int startY) {
	int target_paper = arr[startX][startY];
	bool flag = true;
	for (int i = startX; i < startX + size; i++) {
		for (int j = startY; j < startY + size; j++) {
			if (arr[i][j] != target_paper) {
				flag = false;
				int new_size = size / 2;
				check_paper(arr, new_size, startX, startY);
				check_paper(arr, new_size, startX + new_size, startY);
				check_paper(arr, new_size, startX, startY + new_size);
				check_paper(arr, new_size, startX + new_size, startY + new_size);
				break;
			}
		}
		if (!flag) break;
	}

	// cout << startX << ' ' << startY << endl;
	if (flag) result[target_paper]++;
}