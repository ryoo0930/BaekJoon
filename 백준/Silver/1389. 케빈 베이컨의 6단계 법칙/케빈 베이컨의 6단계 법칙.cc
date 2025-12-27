#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int BFS(const vector<vector<int>>& graph, int v, int targetV);
void private_BFS(const vector<vector<int>>& graph, vector<int>& distance, queue<int>& q, int v);

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    int v = 0, e = 0; cin >> v >> e;
    vector<vector<int>> graph(v + 1);

    for(int i = 0; i < e; i++) {
        int v1 = 0, v2 = 0; cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int result = -1, distance = INT_MAX;
    for(int i = 1; i <= v; i++) {
        int currentDistance = BFS(graph, v, i);
        if(distance > currentDistance) { result = i; distance = currentDistance; } 
    }
    
    cout << result << '\n';
}

int BFS(const vector<vector<int>>& graph, int v, int targetV) {
    vector<int> distance(v + 1, -1);
    queue<int> q;

    private_BFS(graph, distance, q, targetV);


    int result = 0;
    for(int i = 1; i <= v; i++) result += distance[i];

    return result;
}

void private_BFS(const vector<vector<int>>& graph, vector<int>& distance, queue<int>& q, int v) {
    q.push(v); distance[v] = 0;

    while(!q.empty()) {
        int current = q.front(); q.pop();
        for(auto i : graph[current]) {
            if(distance[i] == -1) { q.push(i); distance[i] = distance[current] + 1; }
        }
    }
}