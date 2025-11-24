#include <bits/stdc++.h>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> DFSvector;
vector<int> BFSvector;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

void DFS(int vertex);
void BFS(int vertex);

int main() {
    fastIO(); 

    cin >> N >> M >> V;
    
    graph.resize(N + 1);
    visited.resize(N + 1, false); 

    for(int i = 0; i < M; i++) {
        int v1, v2; cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i = 1; i <= N; i++) { sort(graph[i].begin(), graph[i].end()); }
    
    DFS(V);
    
    fill(visited.begin(), visited.end(), false);
    BFS(V);

    for(auto i : DFSvector) cout << i << ' ';
    cout << '\n';
    for(auto i : BFSvector) cout << i << ' ';
    cout << '\n';

    return 0;
}

void DFS(int vertex) {
    visited[vertex] = true;
    DFSvector.push_back(vertex);

    for(auto i : graph[vertex]) {
        if(!visited[i]) DFS(i); 
    }
}

void BFS(int vertex) {
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    BFSvector.push_back(vertex);

    while(!q.empty()) {
        int targetV = q.front(); q.pop();
        for(auto i : graph[targetV]) {
            if(visited[i]) continue;
            
            visited[i] = true;
            BFSvector.push_back(i);
            q.push(i);
        }
    }
}