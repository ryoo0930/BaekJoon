#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

void innerDFS(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int currentNode, int currentDistance);
void DFS(vector<vector<pair<int, int>>>& graph, int startV);

int main() {
    fastIO(); solve(); return 0;
}

int maxNode = -1, maxDistance = -1;
int n = -1;

void solve() {
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i = 0; i < n; i++) {
        int currentV = 0; cin >> currentV;
        while(true) {
            int targetV = 0; cin >> targetV; if(targetV == -1) break;
            int targetW = 0; cin >> targetW;

            graph[currentV].push_back(make_pair(targetV, targetW));
        }
    }


    DFS(graph, 1); maxDistance = 0;
    DFS(graph, maxNode);
    cout << maxDistance << '\n';
}

void DFS(vector<vector<pair<int, int>>>& graph, int startV) {
    vector<bool> visited(n + 1, false);
    innerDFS(graph, visited, startV, 0);
}

void innerDFS(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int currentNode, int currentDistance) {
    visited[currentNode] = true;
    if(maxDistance < currentDistance) { maxNode = currentNode; maxDistance = currentDistance; }

    for(auto next : graph[currentNode]) {
        if(visited[next.first]) continue;
        innerDFS(graph, visited, next.first, currentDistance + next.second);
    }
}