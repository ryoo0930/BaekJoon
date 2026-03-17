#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

int N, R, Q;
vector<vector<int>> graph;
vector<int> dp;
vector<bool> visited;

int DFS(int v);

void solve() {    
    cin >> N >> R >> Q;
    graph.assign(N + 1, vector<int>());

    for(int i = 0; i < N - 1; i++) {
        int v1, v2; cin >> v1 >> v2;
        graph[v1].push_back(v2); graph[v2].push_back(v1);
    }

    dp.assign(N + 1, 1);
    visited.assign(N + 1, false);

    DFS(R);
    
    for(int i = 0; i < Q; i++) {
        int q; cin >> q;
        cout << dp[q] << '\n';
    }


}

int DFS(int v) {
    visited[v] = true;

    for(auto current : graph[v]) {
        if(visited[current]) continue;
        dp[v] += DFS(current);
    }
    return dp[v];
}