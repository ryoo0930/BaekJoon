#include <algorithm>
#include <iostream>
#include <queue>


using namespace std;
void BFS(int** graph, int** result, pair<int, int> pos);
int height = 0, width = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> height >> width;

	int** graph = new int* [height];
	for (int i = 0; i < height; i++) graph[i] = new int[width];
	int** result = new int* [height];
	for (int i = 0; i < height; i++) { result[i] = new int[width]; fill_n(result[i], width, -1); }

	int startX = 0, startY = 0;
	for (int i = 0; i < height; i++) { 
		for (int j = 0; j < width; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) result[i][j] = 0;
			if (graph[i][j] == 2) { startX = j; startY = i; }
		}
	}

	result[startY][startX] = 0;
	pair<int, int> pos = make_pair(startY, startX);
	BFS(graph, result, pos);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

void BFS(int** graph, int** result, pair<int, int> pos) {
	queue<pair<int, int>> q;
	
	q.push(pos);

	int dy[4] = { 1, 0, -1, 0 };
	int dx[4] = { 0, 1, 0, -1 };

	while (!q.empty()) {
		pair<int, int> current = q.front(); q.pop();
		int currentY = current.first, currentX = current.second;

		for (int i = 0; i < 4; i++) {
			int targetY = currentY + dy[i], targetX = currentX + dx[i];

			if ((targetY >= 0 && targetY < height) && (targetX >= 0 && targetX < width) && result[targetY][targetX] == -1 && graph[targetY][targetX] == 1) {
				result[targetY][targetX] = result[currentY][currentX] + 1;
				q.push(make_pair(targetY, targetX));
			}
		}
	}
}