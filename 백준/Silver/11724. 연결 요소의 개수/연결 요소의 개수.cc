#include <algorithm>
#include <iostream>

using namespace std;

void DFS(int** graph, bool* visited, int vertex_size, int start_vertex);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int vertex_size = 0, edge_size = 0;
	cin >> vertex_size >> edge_size;

	int** graph = new int* [vertex_size + 1];
	for (int i = 0; i <= vertex_size; i++) graph[i] = new int[vertex_size + 1] {0};
	bool* visited = new bool[vertex_size + 1] { false };

	for (int i = 0; i < edge_size; i++) {
		int v1, v2; cin >> v1 >> v2;
		graph[v1][v2] = 1; graph[v2][v1] = 1;
	}

	int result = 0;
	for (int i = 1; i <= vertex_size; i++) {
		if (visited[i] == false) { DFS(graph, visited, vertex_size, i); result++; }
	}

	cout << result;


	return 0;
}

void DFS(int** graph, bool* visited, int vertex_size, int start_vertex) {
	visited[start_vertex] = true;
	for (int i = 1; i <= vertex_size; i++) {
		if (visited[i] == false && graph[start_vertex][i] == 1) DFS(graph, visited, vertex_size, i);
	}
}
