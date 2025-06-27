#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

void search_(int size, int startX, int startY, int targetX, int targetY);
int before_count(int size);

int result = 0;

int main(void) {
	int N, r, c;
	cin >> N >> r >> c;
	int size = 1 << N;

	search_(size, 0, 0, c, r);
	cout << result;

	return 0;
}



void search_(int size, int startX, int startY, int targetX, int targetY) {
	if (size == 1) { return; }

	int count = (size / 2) * (size / 2);

	int half_size = size / 2; 
	bool whereX = false, whereY = false;
	if (targetX >= startX + half_size) whereX = true;
	if (targetY >= startY + half_size) whereY = true;

	if (!whereX && !whereY) {
		return search_(half_size, startX, startY, targetX, targetY);
	}
	else if (whereX && !whereY) { 
		result += count;
		return search_(half_size, startX + half_size, startY, targetX, targetY);
	}
	else if (!whereX && whereY) { 
		result += count * 2;
		return search_(half_size, startX, startY + half_size, targetX, targetY);
	}
	else if (whereX && whereY) {
		result += count * 3;
		return search_(half_size, startX + half_size, startY + half_size, targetX, targetY);
	}
}