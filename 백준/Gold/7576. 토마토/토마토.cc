#include <algorithm>
#include <iostream>
#include <queue>


using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int width = 0, height = 0; cin >> width >> height;
	queue<pair<int, int>> q;

	int** graph = new int* [height];
	int** result = new int* [height];
	for (int i = 0; i < height; i++) { graph[i] = new int[width]; result[i] = new int[width]; fill_n(result[i], width, -1); }

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) { q.push(make_pair(i, j)); result[i][j] = 0; }
		}
	}

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	while (!q.empty()) {
		int currentY = q.front().first, currentX = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int targetY = currentY + dy[i], targetX = currentX + dx[i];
			if ((targetX >= 0 && targetX < width) && (targetY >= 0 && targetY < height) && graph[targetY][targetX] != -1 && result[targetY][targetX] == -1) {
				result[targetY][targetX] = result[currentY][currentX] + 1;
				q.push(make_pair(targetY, targetX));
			}
		}
	}

	int max = 0; bool flag = false;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (result[i][j] == -1 && graph[i][j] != -1) { max = -1; flag = true; break; }
			if (result[i][j] > max) max = result[i][j];
		}
		if (flag) break;
	}
	cout << max;

	return 0;
}
