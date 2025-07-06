#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int height = 0, width = 0; cin >> height >> width;
	int inventory = 0; cin >> inventory;

	int** arr = new int* [height];
	for (int i = 0; i < height; i++) arr[i] = new int[width];

	for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) cin >> arr[i][j];


	int max_height = -1;
	int low_time = numeric_limits<int>::max();
	for (int i = 0; i <= 256; i++) {
		int targetHeight = i;
		int time = 0;

		int needBlock = 0, breakBlock = 0;
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				if (arr[j][k] < targetHeight) needBlock += targetHeight - arr[j][k];
				else if (arr[j][k] > targetHeight) breakBlock += arr[j][k] - targetHeight;
			}
		}
		if (needBlock > breakBlock + inventory) continue;
		time = needBlock + 2 * breakBlock;
		if (time <= low_time) {
			low_time = time;
			max_height = targetHeight;
		}
	}
	cout << low_time << ' ' << max_height;
	return 0;
}