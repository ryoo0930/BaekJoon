#include <algorithm>
#include <iostream>

using namespace std;


void DFS(char** graph, bool** visited, int N, int M, pair<int, int>pos);

int result = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, M = 0; cin >> N >> M;
	char** graph = new char* [N];
	bool** visited = new bool* [N];
	for (int i = 0; i < N; i++) { graph[i] = new char[M]; visited[i] = new bool[M] {false}; }

	pair<int, int> I_pos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'I') I_pos = make_pair(i, j);
		}
	}

	DFS(graph, visited, N, M, I_pos);
	if (result == 0)cout << "TT";
	else cout << result;

	return 0;
}

void DFS(char** graph, bool** visited, int N, int M, pair<int, int>pos) {
	int currentY = pos.first, currentX = pos.second;
	visited[currentY][currentX] = true;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++) {
		int targetY = currentY + dy[i], targetX = currentX + dx[i];
		if (((targetY >= 0 && targetY < N) && (targetX >= 0 && targetX < M)) && visited[targetY][targetX] == false && graph[targetY][targetX] != 'X') {
			if (graph[targetY][targetX] == 'P') result++;
			DFS(graph, visited, N, M, make_pair(targetY, targetX));
		}
	}
}