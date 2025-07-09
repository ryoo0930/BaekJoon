#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> arr, int currentIndex, int depth);
int N = 0, M = 0;


int main(void) {
	cin >> N >> M;
	vector<int> arr(N);

	DFS(arr, 1, 0);

	return 0;
}

void DFS(vector<int> arr, int currentIndex, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = currentIndex; i <= N; i++) {
		arr[depth] = i;
		DFS(arr, i + 1, depth + 1);
	}

}