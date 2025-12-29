#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();
void BFS(const vector<vector<int>>& graph, int n, int startV);

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    int n = 0; cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        BFS(graph, n, i);
    }
    


}

void BFS(const vector<vector<int>>& graph, int n, int startV){
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(startV);

    while(!q.empty()) {
        int currentV = q.front(); q.pop();
        for(int i = 1; i <= n; i++) {
            if(graph[currentV][i] == 1 && visited[i] == false) { q.push(i); visited[i] = true; }
        }
        
    }

    for(int i = 1; i <= n; i++) {
        if(visited[i]) cout << '1' << ' ';
        else cout << '0' << ' ';
    }
    cout << '\n';
}