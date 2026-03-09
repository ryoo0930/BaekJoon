#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int N; 
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visited;

void DFS(int startV);

int main() {
    fastIO(); 
    solve(); 
    return 0;
}

void solve() {    
    cin >> N;
    graph.assign(N + 1, vector<int>()); dp.assign(N + 1, vector<int>(2)); visited.assign(N + 1, false);

    for(int i = 0; i < N - 1; i++) {
        int v1, v2; cin >> v1 >> v2;
        graph[v1].push_back(v2); graph[v2].push_back(v1);
    }
    DFS(1);

    cout << min(dp[1][0], dp[1][1]);
}

void DFS(int target) {
    visited[target] = true;
    
    dp[target][0] = 0; dp[target][1] = 1;

    for(auto v : graph[target]) {
        if(!visited[v]) {
            DFS(v);
            dp[target][0] += dp[v][1];
            dp[target][1] += min(dp[v][0], dp[v][1]);
        }
    }
}