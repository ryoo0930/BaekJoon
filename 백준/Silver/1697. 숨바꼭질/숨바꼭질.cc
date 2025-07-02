#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int currentPos = 0, targetPos = 0; cin >> currentPos >> targetPos;

	vector<int> visited(MAX, -1);
	queue<int> q;

	visited[currentPos] = 0; q.push(currentPos);
	while (!q.empty()) {
		int current = q.front(); q.pop();
		if (current == targetPos) { cout << visited[targetPos]; break; }

		int move[3] = { current + 1, current - 1, current * 2 };
		for (int i = 0; i < 3; i++) {
			int next = move[i];
			if (next >= 0 && next < MAX && visited[next] == -1) { visited[next] = visited[current] + 1; q.push(next); }
		}
	}

	return 0;
}